#include <Adafruit_NeoPixel.h>

#define LED         3
#define TOUCH       2
#define NUMPIXELS   12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);

unsigned long startTime;
unsigned long touchTime;

int count = 0;

void ledOn(byte repeat);
void ledOff();

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(TOUCH, INPUT);
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(TOUCH) == HIGH){
    count++;
    startTime = millis();

    while(digitalRead(TOUCH) == HIGH){
      touchTime = millis() - startTime;  // 0으로 수렴
      if(touchTime >= 2000){
        ledOff();
        count = 0;
      }
    }
  }

  switch(count){
    case 1:
    case 2:
    case 3:
      ledOn(count);
      delay(200);
      break;
    case 4:
      ledOff();
      delay(200);
      count = 0;
      break;
  }
}

void ledOn(byte repeat){
  for(int q = 0; q < repeat; q++){
    for(int i = 0; i < pixels.numPixels(); i = i + 3){
      pixels.setPixelColor(i + q, pixels.Color(255, 255, 255));
    }
  }
  pixels.show();
}

void ledOff(){
  for(int i = 0; i < pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
}