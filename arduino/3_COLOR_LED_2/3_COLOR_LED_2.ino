#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9
#define TOUCH_STATE 7

void colorPrint(int R, int G, int B);





int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);      // 9, 10, 11 번 핀을 출력으로 설정
  pinMode(TOUCH_STATE, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(TOUCH_STATE);

  if(touchValue == HIGH){
    count++;
    delay(300);
    switch(count){
      case 1:
        colorPrint(255, 255, 255);  // 흰색
        break;
      case 2:
        colorPrint(255, 0, 0);      // 빨간색
        break;
      case 3:
        colorPrint(0, 255, 0);      // 초록색
        break;
      case 4:
        colorPrint(0, 0, 255);      // 파란색
        break;
      case 5:
        colorPrint(0, 216, 255);    // 하늘색
        break;
      case 6:
        colorPrint(95, 0, 255);     // 보라색
        break;
      default :
        colorPrint(0, 0, 0);         // off
        count = 0;
    }
  }
}

void colorPrint(int R, int G, int B){
  analogWrite(RED_PIN, R);
  analogWrite(GREEN_PIN, G);
  analogWrite(BLUE_PIN, B);
}
