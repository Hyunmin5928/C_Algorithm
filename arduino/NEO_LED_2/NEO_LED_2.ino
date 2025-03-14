#include <Adafruit_NeoPixel.h>
#define PIN 3
#define TOUCH 2
#define NUMPIXELS 12

// 네오픽셀 LED 초기 설정
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// 두 개의 매개변수를 가진 colorWipe 함수 선언
void colorWipe(uint32_t color, uint8_t wait); 
// 두 개의 매개변수를 가진 theaterChase 함수 선언
void theaterChase(uint32_t color, uint8_t wait);
// 한 개의 매개변수와 int형을 반환하는 Wheel 함수 선언
uint32_t Wheel(byte WheelPos);
// 한 개의 매개변수를 가진 rainbow 함수 선언
void rainbow(uint8_t wait);

int count = 0;
int wait = 200;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(TOUCH, INPUT);
  pixels.begin(); // 핀 모드 설정
}

void loop() 
{
  // put your main code here, to run repeatedly:
  int Value = digitalRead(TOUCH);

  if(Value == HIGH){
    count++;
    switch(count) {
      case 1:
        // 하나의 색깔로 픽셀을 순차적으로 채우고 다른 색깔로 전환
        // colorWipe(pixels.Color(255, 0, 0), 50); // 빨간색
        // colorWipe(pixels.Color(0, 255, 0), 50); // 초록색
        // colorWipe(pixels.Color(0, 0, 255), 50); // 파랑색
        // // 3개 간격으로 픽셀에 색깔이 동시에 출력되고 한 칸씩 이동
        // theaterChase(pixels.Color(255, 255, 255), 50); // 흰색
        // theaterChase(pixels.Color(255, 0, 0), 50); // 빨간색
        // theaterChase(pixels.Color(0, 0, 255), 50); // 파란색
        // 전체 픽셀이 무지개 색깔을 순차적으로 출력
        rainbow(20);
      case 2:
        count = 0;
        int i;
        for(i = 0; i < pixels.numPixels(); i++)
        {
          pixels.setPixelColor(i, 0, 0, 0);
          
        }
        pixels.show();
        delay(wait);
        break;
    }
  }
  
}

// RGB 값과 대기 시간을 매개변수로 받음
void colorWipe(uint32_t color, uint8_t wait)
{   
  for(int i = 0; i < pixels.numPixels(); i++)
  {    // 전체 픽셀 수만큼 반복
    pixels.setPixelColor(i, color);   // 해당 픽셀에 색깔 설정
    pixels.show();                    // 해당 픽셀에 색깔을 출력
    delay(wait);                      // 0.05초 대기
  }
}

// RGB 값과 대기 시간을 매개변수로 받음
void theaterChase(uint32_t color, uint8_t wait)
{
  for(int j = 0; j < 10; j++)   // 전체 동작 10회 반복
  {
    for(int q = 0; q < 3 ; q++) // 아래 색깔 설정을 3회 반복
    {
      for(int i = 0; i < pixels.numPixels(); i = i + 3) 
      {
        pixels.setPixelColor(i + q, color);   // 3개 간격으로 픽셀 설정
      }
      pixels.show();
      delay(wait);

      for (int i = 0; i < pixels.numPixels(); i = i + 3)
      {
        pixels.setPixelColor(i + q, 0);       // 3개 간격으로 픽셀 off
      }
    }
  }
}

// RGB 값을 반환
uint32_t Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85)
  {
    // 파란색 ~ 빨간색 사이의 RGB 값 반환
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170)
  {
    WheelPos -= 85;
    // 초록색 ~ 파란색 사이의 RGB 값 반환
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  // 빨간색 ~ 초록색 사이의 RGB 값 반환
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// 
void rainbow(uint8_t wait)
{
  int i, j;
  for(j = 0; j < 256; j++)
  {
    for(i = 0; i < pixels.numPixels(); i++)
    {
      pixels.setPixelColor(i, Wheel((i + j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}

