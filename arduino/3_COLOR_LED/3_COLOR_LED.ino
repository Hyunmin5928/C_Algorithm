#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);      // 9, 10, 11 번 핀을 출력으로 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  // analogWrite(RED_PIN, 255);
  // analogWrite(GREEN_PIN, 0);
  // analogWrite(BLUE_PIN, 0);
  // delay(1000);

  // analogWrite(RED_PIN, 0);
  // analogWrite(GREEN_PIN, 255);
  // analogWrite(BLUE_PIN, 0);
  // delay(1000);

  // analogWrite(RED_PIN, 0);
  // analogWrite(GREEN_PIN, 0);
  // analogWrite(BLUE_PIN, 255);
  // delay(1000);    


  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);
  delay(1000);

}
