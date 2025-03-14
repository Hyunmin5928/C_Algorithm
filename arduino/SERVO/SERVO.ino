#include <Servo.h>

#define SERVO 6

Servo myservo;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(pos = 0; pos <= 120; pos++){
    myservo.write(pos);
    delay(50);
  }
  for(pos = 120; pos >= 0; pos--){
    myservo.write(pos);
    delay(50);
  }
}
