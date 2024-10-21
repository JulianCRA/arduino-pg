#include <Adafruit_NeoPixel.h>

#define LED_PIN    3
#define LED_COUNT 3

Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int r = 0;
void setup() {
  pixels.begin();           
  pixels.setBrightness(255); 
 
  pixels.show();            

}
bool strobe = false;
int blinks = 50;
void loop() {
  if(!strobe){
    pixels.setPixelColor(0, pixels.Color(r, 0, 0));
    pixels.setPixelColor(1, pixels.Color(r, 0, 0));
    pixels.setPixelColor(2, pixels.Color(r, 0, 0));
    pixels.show();
    r = r + 2;
    delay(100);
    if(r >= 255){
      strobe = true;
    }
  }
  else{
    if (blinks > 0){
      blinks--;
      uint32_t c = pixels.getPixelColor(0);
      r = (c >> 16) & 0xFF;

      if(r != 0){
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
        pixels.setPixelColor(1, pixels.Color(0, 0, 0));
        pixels.setPixelColor(2, pixels.Color(0, 0, 0));
      }
      else{
        pixels.setPixelColor(0, pixels.Color(255, 0, 0));
        pixels.setPixelColor(1, pixels.Color(255, 0, 0));
        pixels.setPixelColor(2, pixels.Color(255, 0, 0));
      }
      pixels.show();
      delay(50);
    }
    else{
      blinks = 50;
      strobe = false;
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));
      pixels.setPixelColor(1, pixels.Color(255, 0, 0));
      pixels.setPixelColor(2, pixels.Color(255, 0, 0));
      pixels.show();
      delay(1000);
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.setPixelColor(1, pixels.Color(0, 0, 0));
      pixels.setPixelColor(2, pixels.Color(0, 0, 0));
      pixels.show();
      delay(2000);
    }
  }
  
}
