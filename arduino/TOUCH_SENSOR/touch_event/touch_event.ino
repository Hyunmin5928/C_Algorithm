#define TOUCH_STATE 7

void setup() {
  // put your setup code here, to run once:
  pinMode(TOUCH_STATE, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(TOUCH_STATE);

  if(touchValue == HIGH){
    Serial.println("Touched");
    delay(200);
  }
}
