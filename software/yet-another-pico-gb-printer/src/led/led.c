#include "led.h"

Adafruit_NeoPixel LedPixels(kLedNumPixels, kIoLedStatusPin, NEO_RGB);

uint32_t kLedWs2812Color = LedPixels.Color(0, intensity, 0);     //RGB triplet, default is green, turns to blue in tear mode
uint32_t kLedWs2812SdCrash = LedPixels.Color(intensity, 0, 0);  //RGB triplet, turn to red, issue with SD card
uint32_t kLedWs2812Idle = LedPixels.Color(1, 1, 1);          


void LedInit(void) {
  LedPixels.begin();
  LedPixels.setBrightness(kLedIntensity);
  LedPixels.show();
}