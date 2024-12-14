#ifndef __LED__H__
#define __LED__H__

#include <Adafruit_NeoPixel.h>
#include "led_config.h"
#include "io.h"

extern Adafruit_NeoPixel LedPixels;
extern void LedInit(void);
#endif