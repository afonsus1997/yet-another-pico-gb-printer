#include "led.h"



Adafruit_NeoPixel LedPixels(kLedNumPixels, kIoLedStatusPin, NEO_RGB);

uint32_t kLedWs2812Color;
uint32_t kLedWs2812SdCrash;
uint32_t kLedWs2812Idle;          


void LedInit(void) {
  LedPixels.begin();

  kLedWs2812Color   = LedPixels.Color(0, kLedIntensity, 0);
  kLedWs2812SdCrash = LedPixels.Color(kLedIntensity, 0, 0);
  kLedWs2812Idle    = LedPixels.Color(1, 1, 1);
}