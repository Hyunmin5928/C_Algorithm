#define MOTOR 7
#define TOUCH 6

int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR, OUTPUT);
  pinMode(TOUCH, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(TOUCH);
  delay(200);

  if(touchValue == HIGH){
    count++;
    switch(count){
      case 1:
        analogWrite(MOTOR, 85);   // 1/3
        break;
      case 2:
        analogWrite(MOTOR, 170);   // 2/3
        break;
      case 3:
        analogWrite(MOTOR, 255);   // 1
        break;
      case 4:
        analogWrite(MOTOR, 0);
        count = 0;
        break;
    }
  }
}
