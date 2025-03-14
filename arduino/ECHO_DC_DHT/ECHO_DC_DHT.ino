#include "DHT.h"

#define ECHO 2
#define TRIG 3
#define RED 10
#define GREEN 11
#define BLUE 12
#define MOTOR 5
#define DHT_PIN 4
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(MOTOR, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  float di = (float)9/5*t - 0.55*((float)1 - h/100)*((float)9/5*t-26)+32;

  long duration = pulseIn(ECHO, HIGH);
  if(duration == 0){
    return;
  }

  if(isnan(h)||isnan(t)){
    Serial.println("Failed to read from DHT Sensor!");
    return;
  }

  long d = duration / 58;
  Serial.print("Distance : "); 
  Serial.print(d);
  Serial.print("cm\n");
  Serial.print("Discomfor Index : ");
  Serial.print(di, 1);
  Serial.print("\n");

  if(d <= 50 && di >= 75){
    analogWrite(RED, 255);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 0);
    analogWrite(MOTOR, 255);
  }
  else if(di >= 65 && d <= 50){
    analogWrite(RED, 0);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 255);
    analogWrite(MOTOR, 130);
  }
  else{
    analogWrite(RED, 0);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 255);
    analogWrite(MOTOR, 0);
  }
  delay(2000);
}
