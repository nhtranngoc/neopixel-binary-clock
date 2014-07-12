#include <Adafruit_NeoPixel.h>
#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>

#define FIRST_PIN 8
#define SECOND_PIN 9
#define THIRD_PIN 10
#define FOURTH_PIN 11
#define FIFTH_PIN 12
#define SIXTH_PIN 13



Adafruit_NeoPixel firstStrip  = Adafruit_NeoPixel (10, FIRST_PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel secondStrip = Adafruit_NeoPixel (10, SECOND_PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel thirdStrip  = Adafruit_NeoPixel (10, THIRD_PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel fourthStrip = Adafruit_NeoPixel (10, FOURTH_PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel fifthStrip  = Adafruit_NeoPixel (10, FIFTH_PIN, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel sixthStrip  = Adafruit_NeoPixel (10, SIXTH_PIN, NEO_RGB + NEO_KHZ800);

uint32_t green = firstStrip.Color(255, 0, 0);
uint32_t red = firstStrip.Color(0, 255, 0);
uint32_t blue = firstStrip.Color(0, 0, 255);

void setup() {
  // put your setup code here, to run once:
  firstStrip.begin();
  secondStrip.begin();
  thirdStrip.begin();
  fourthStrip.begin();
  fifthStrip.begin();
  sixthStrip.begin();
   
  showAll();
}

void loop() {
  tmElements_t tm;
  
  if(RTC.read(tm)){
    
    int hUnit = tm.Hour%10;
    int hTen = tm.Hour/10;
    int mUnit = tm.Minute%10;
    int mTen = tm.Minute/10;
    int sUnit = tm.Second%10;
    int sTen = tm.Second/10;

    displayStrip(hTen, firstStrip, red);
    displayStrip(hUnit, secondStrip, red);
    displayStrip(mTen, thirdStrip, green);
    displayStrip(mUnit, fourthStrip, green);
    displayStrip(sTen, fifthStrip, blue);
    displayStrip(sUnit, sixthStrip, blue);
  } else{
    if (RTC.chipPresent()){
      firstStrip.setPixelColor(0, red);
      firstStrip.show();
    } else{
      sixthStrip.setPixelColor(0, red);
      sixthStrip.show();
    }
    delay(9000);
  }
  delay(1000);
}

void showAll(){
  firstStrip.show();
  secondStrip.show();
  thirdStrip.show();
  fourthStrip.show();
  fifthStrip.show();
  sixthStrip.show();
}

void displayStrip(int num, Adafruit_NeoPixel strip, uint32_t color){ //take in number, display neopixel accordingly
  switch (num){
    case 0:
      break;
    case 1:
      strip.setPixelColor(0, color);
//      strip.show();
      break;
    case 2:
      strip.setPixelColor(1, color);
//      strip.show();
      break;
    case 3:
      strip.setPixelColor(1, color);
      strip.setPixelColor(0, color);
//      strip.show();
      break;
    case 4:
      strip.setPixelColor(2, color);
//      strip.show();
      break;
    case 5:
      strip.setPixelColor(2, color);
      strip.setPixelColor(0, color);
//      strip.show();
      break;
    case 6:
      strip.setPixelColor(2, color);
      strip.setPixelColor(1, color);
//      strip.show();
      break;
    case 7:
      strip.setPixelColor(2, color);
      strip.setPixelColor(1, color);
      strip.setPixelColor(0, color);
//      strip.show();
      break;
    case 8: 
      strip.setPixelColor(3, color);
//      strip.show();
      break;
    case 9:
      strip.setPixelColor(3, color);
      strip.setPixelColor(0, color);
//      strip.show();
      break;
  }
   delay(1); //delay for stability   
}
