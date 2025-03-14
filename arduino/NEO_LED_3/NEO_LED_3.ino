#include <Adafruit_NeoPixel.h>

#define PIN         6
#define NUMPIXELS   12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void ledOn(byte repeat);
void ledOff();

int count = 1;

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(count){
    case 1:
    case 2:
    case 3:
      ledOff();
      // ledOn(count);
      delay(200);
      count++;
      break;
    case 4:
      ledOff();
      delay(200);
      count = 1;
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
  for(int i = 0; i < pixels.numPixels(); i ++){
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
}