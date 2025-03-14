#include <Servo.h>

#define TOUCH 7
#define DC_MOTOR 5

Servo myservo;

int motorStep   = 0;
int rotateState = 0;
int pos         = 0;

unsigned long startTime;
unsigned long touchTime;
float touchTimesec;

void motor_Control(int dcStep);

void setup() {
  // put your setup code here, to run once:
  pinMode(TOUCH, INPUT);
  // pinMode(DC_MOTOR, OUTPUT);
  myservo.attach(6);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(TOUCH);
  delay(200);

  if(touchValue == HIGH){
    motorStep++;
    Serial.print("Touch Count : ");
    Serial.print(motorStep);
    Serial.print("\n");

    motor_Control(motorStep);

    startTime = millis();
    while(digitalRead(TOUCH) == HIGH){
      touchTime = millis() - startTime;
      touchTimesec = float(touchTime) / 1000;
      Serial.print("\nTouch Time : ");
      Serial.print(touchTimesec);
      Serial.print("s\n");
    }
    if(touchTime >= 1000 && touchTime <= 3000){
      rotateState++;
    }
  }
  
  if((rotateState % 2 == 1) && (motorStep != 0)){
    Serial.print("Touch Count : ");
    Serial.print(motorStep);
    for(pos = 0; pos <= 120; pos++){
      motor_Control(motorStep);
      myservo.write(pos);
      delay(20);
    }
    for(pos = 120; pos >= 0; pos--){
      motor_Control(motorStep);
      myservo.write(pos);
      delay(20);
    }
  }
}


void motor_Control(int dcStep){
  switch(dcStep){
    case 1:
      analogWrite(DC_MOTOR, 50);
      break;
    case 2:
      analogWrite(DC_MOTOR, 150);
      break;
    case 3:
      analogWrite(DC_MOTOR, 255);
      break;
    case 4:
      analogWrite(DC_MOTOR, 0);
      motorStep = 0;
      break;
  }   
}