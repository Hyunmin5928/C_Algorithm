#define ECHO 2
#define TRIG 3

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
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
  delay(2000);
}
