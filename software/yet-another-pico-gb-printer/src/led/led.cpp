#include "led.h"



Adafruit_NeoPixel LedPixels(kLedNumPixels, kIoLedStatusPin, NEO_GRB + NEO_KHZ800);

uint32_t kLedWs2812Color;
uint32_t kLedWs2812SdCrash;
uint32_t kLedWs2812Idle;          


void LedInit(void) {
  LedPixels.begin();
  LedPixels.setBrightness(kLedIntensity);

  kLedWs2812Color   = LedPixels.Color(0, 255, 0);
  kLedWs2812SdCrash = LedPixels.Color(255, 0, 0);
  kLedWs2812Idle    = LedPixels.Color(255, 255, 255);

  LedPixels.clear();                               // optional, clears all pixels
  LedPixels.setPixelColor(0, kLedWs2812Idle);      // set first pixel to idle color
  LedPixels.show();    

}

