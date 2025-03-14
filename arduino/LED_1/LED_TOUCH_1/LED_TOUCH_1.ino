#define RED 6
#define GREEN 7
#define TOUCH_STATE 8

int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(TOUCH_STATE, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(TOUCH_STATE);

  if(touchValue == HIGH){
    count++;
  }

  if(count%2 == 1){
    digitalWrite(GREEN,LOW);
    delay(200);
    digitalWrite(RED,HIGH);
    delay(200);
    digitalWrite(RED,LOW);
    delay(200);
  }
  else{
    digitalWrite(RED,LOW);
    delay(200);
    digitalWrite(GREEN,HIGH);
  }
}
