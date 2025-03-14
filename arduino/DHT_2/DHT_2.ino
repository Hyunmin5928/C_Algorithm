#include "DHT.h"

#define DHT_PIN 2
#define MOTOR 6
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);

float calc_di(float h, float t);

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
  Serial.print("Start \n");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();       // 습도 데이터
  float t = dht.readTemperature();    // 온도 데이터

  float di = calc_di(h, t);
  delay(2000);

  if(isnan(h) || isnan(t)){
    Serial.print("Can't read Sensor data\n");
    return;
  }

  Serial.print("Discomfort Index : ");
  Serial.print(di, 1);
  Serial.print("\n");

  if(75 > di && di >= 65){
    analogWrite(MOTOR, 30);
  }
  else if(di >= 75){
    analogWrite(MOTOR, 255);
  }
  else{
    analogWrite(MOTOR, 0);
  }
}

float calc_di(float h, float t){
  return (float)9/5 * t - 0.55*((float)1 - h/100) * ((float)9/5 * t - 26) + 32;
}
