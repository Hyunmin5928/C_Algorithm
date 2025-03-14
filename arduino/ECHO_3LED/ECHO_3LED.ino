#define ECHO 10
#define TRIG 11
#define RED 5
#define GREEN 4
#define BLUE 3

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long t = pulseIn(ECHO, HIGH);
  if(t == 0){
    return;
  }

  long d = t / 58;
  Serial.print("Distance : "); 
  Serial.print(d);
  Serial.print("cm\n");

  if(d <= 15){
    analogWrite(RED, 255);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 0);
  }
  else{
    analogWrite(RED, 0);
    analogWrite(GREEN, 255);
    analogWrite(BLUE, 0);
  }
  delay(2000);
}
