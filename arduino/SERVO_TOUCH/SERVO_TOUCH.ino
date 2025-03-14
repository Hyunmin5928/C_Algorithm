#include <Servo.h>

#define SERVO 6
#define TOUCH 7

Servo myservo;

int pos = 0;
int rS  =  0;

unsigned long sT;
unsigned long tT;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(SERVO);
  pinMode(TOUCH, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(TOUCH);

  if(touchValue == HIGH){
    sT = millis();
    while(digitalRead(TOUCH) == HIGH){
      tT = millis() - sT;
      Serial.print("Touch time : ");
      Serial.print(tT);
      Serial.print("\n");
    }
    if(tT >= 1000 && tT <= 3000){
      rS++;
    }
    Serial.print("rotateState : ");
    Serial.print(rS);
    float tTs = tT / 100;
    Serial.print("\t");
    Serial.print(tTs);
    Serial.print("s\n");
  }
  if(rS%2 == 1){
    for(pos = 0; pos <= 120; pos++){
      myservo.write(pos);
      delay(15);
    }
    for(pos = 120; pos >= 0; pos--){
      myservo.write(pos);
      delay(15);
    }
  }
}
