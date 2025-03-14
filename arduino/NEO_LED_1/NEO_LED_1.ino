#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 12

// 네오픽셀 LED 초기 설정
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;

\void setup() {
  // put your setup code here, to run once:
  pixels.begin(); // 핀 모드 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(delayval);
  }
}
