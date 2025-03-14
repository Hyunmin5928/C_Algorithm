# 이것이 자료구조 + 알고리즘이다 with C언어

make 파일 실행 방법

mingw32-make

이후, exe파일을 실행
test.exe

```cpp
#include <Servo.h>
#include <U8glib.h>
#include <DHT.h>

// 초음파 센서
#define TRIG 2
#define ECHO 3
// 온 습도 센서
#define DHT_OUT 4
#define DHTTYPE DHT11
// DC 모터
#define DC_MOTOR 5
// 서보 모터
#define SERVO 6
// 터치 센서
#define TOUCH   7
// 3색 RGB
#define RED   10
#define GREEN 11
#define BLUE  12

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
DHT dht(DHT_OUT, DHTTYPE);
Servo myservo;

int DC_flag = 0;    // DC 모터 플래그 설정
int tmp_flag;
int Servo_flag = 0;   // 서보 모터 플래그 설정
int auto_flag = 0;    // 자동 플래그

int pos = 0;          // 서보 모터 위치 값 지정(각도)

unsigned long startTime;
unsigned long touchTime;

void colorPrint(int r, int g, int b);
void motor_Control(int dc_flag);

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  dht.begin();
  pinMode(DC_MOTOR, OUTPUT);
  pinMode(SERVO, OUTPUT);
  myservo.attach(SERVO);
  pinMode(TOUCH, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /* 초음파 센서 */
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);  // 2마이크로 초
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH); 
  if(duration == 0){
    Serial.print("Can't read ECHO Sensor data.\n");
    return;
  }
  long d = duration / 58;    // 시간을 58로 나누면 cm 단위로 거리가 나옴

  /* 온 습도 센서 */
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // 불쾌지수 di 계산
  float di = (float)9/5*t - 0.55*((float)1 - h/100)*((float)9/5*t - 26) + 32;
  // 센서 데이터 없을 때
  if(isnan(h) || isnan(t)){
    Serial.print("Can't read DHT Sensor data.\n");
    return;
  }

  /* LED 데이터 출력 */
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_fub14);  // 온도, 습도 폰트 지정
    u8g.setPrintPos(5, 20);       // 온도 데이터 출력 커서(위치) 지정
    u8g.print(t, 1);               // 온도 출력(소수 1자리)
    u8g.print("\xb0""C");         // 온도 기호 출력
    u8g.setPrintPos(70, 20);       // 습도 데이터 출력 커서(위치) 지정
    u8g.print(h, 1);
    u8g.print("%");
    u8g.setFont(u8g_font_fub20);  // 불쾌지수 폰트 지정
    u8g.setPrintPos(40, 55);
    u8g.print(di, 1);
  } while(u8g.nextPage());

  // 3색 LED 제어
  if(di >= 75){
    colorPrint(255, 0, 0);
  }
  else if(di >= 73){
    colorPrint(255, 10, 0);     // 주황색
  }
  else if(di >= 70){
    colorPrint(0, 255, 0);
  }
  else{
    colorPrint(0, 0, 255);
  }

  /* 터치 센서 제어 */
  int touchValue = digitalRead(TOUCH);
  delay(200);

  if(touchValue == HIGH){
    DC_flag++;

    motor_Control(DC_flag);
    startTime = millis();
    while(digitalRead(TOUCH) == HIGH);
    touchTime = millis() - startTime;
    float tTs = (float)touchTime / 1000;
    Serial.print("You touched ");
    Serial.print(tTs);
    Serial.print("s\n");
    // Servo_flag++;
    if(touchTime >= 1000 && touchTime <= 3000){
      Servo_flag++;
    }
    else if(touchTime > 3000){
      auto_flag++;
    }
  }

  /* 서보 모터 제어 */
  if((Servo_flag%2 == 1) && (DC_flag != 0)){
    Serial.print("Servo func active.\n");
    Serial.print("Servo flag : ");
    Serial.print(Servo_flag);
    Serial.print("\n");
    for(pos = 10; pos <= 60; pos++){
      motor_Control(DC_flag);
      myservo.write(pos);
      delay(15);
    }
    for(pos = 60; pos >= 10; pos--){
      motor_Control(DC_flag);
      myservo.write(pos);
      delay(15);
    }
  }
  else if(Servo_flag%2 == 0){
    myservo.write(30);
  }

  /* 자동 플래그 제어 */
  if(auto_flag%2 == 1){
    if(di >= 75 && d <= 30){
      DC_flag = 3;
      motor_Control(DC_flag);
    }
    else if(di >= 70 && d <= 30){
      tmp_flag = 2;
      if(DC_flag > tmp_flag){
        motor_Control(DC_flag);
      }
      else{
        DC_flag = tmp_flag;
        motor_Control(DC_flag);
      }
    }
    else{
      DC_flag = 4;
      motor_Control(DC_flag);
    }
  }

  // 시리얼 모니터 출력
  Serial.print("Touch Count : ");
  Serial.print(DC_flag);
  Serial.print("\tdistance : ");
  Serial.print(d);
  Serial.print("\t di :");
  Serial.print(di, 1);
  Serial.print("\n");
}

void colorPrint(int r, int g, int b){
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void motor_Control(int dc_flag){
  switch(dc_flag){
    case 1:
      analogWrite(DC_MOTOR, 40);
      break;
    case 2:
      analogWrite(DC_MOTOR, 150);
      break;
    case 3:
      analogWrite(DC_MOTOR, 255);
      break;
    case 4:
      analogWrite(DC_MOTOR, 0);
      DC_flag = 0;
      break;
  }
}
```
