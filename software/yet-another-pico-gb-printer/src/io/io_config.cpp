 #include "io_config.h"
#include <Arduino.h>

/* I2C0 Config */
const uint8_t kIoPinI2c0Sda = 0;
const uint8_t kIoPinI2c0Scl = 1;

/* SPI1 Config */
const uint8_t kIoPinSpi1Miso = 8;
const uint8_t kIoPinSpi1Mosi = 11;
const uint8_t kIoPinSpi1Sck = 10;
const uint8_t kIoPinSpi1Cs = 9;

/* OLED Config */
const uint8_t kIoPinOledSda = kIoPinI2c0Sda;
const uint8_t kIoPinOledScl = kIoPinI2c0Scl;

/* Buttons */
const uint8_t kIoButtonPin = 12;

/* Gameboy Link Connector */
// Note: Serial Clock Pin must be attached to an interrupt pin of the arduino
//  ___________
// |  6  4  2  |
//  \_5__3__1_/   (at cable)
//
const uint8_t kIoGbpSoPin = 4;
const uint8_t kIoGbpSiPin = 3;
const uint8_t kIoGbpScPin = 2;

/* NeoPixel LED */
const uint8_t kIoLedStatusPin = 16; 

/* RNG Pin*/
const uint8_t kIoRngPin = 0;

 io_pin_config_t io_pin_config[kIoPinAmmountSize] = {
  /* Buttons */
  {kIoButtonPin, INPUT},
  /* Gameboy Link */
  {kIoGbpSoPin, OUTPUT},
  {kIoGbpSiPin, INPUT},
  {kIoGbpScPin, OUTPUT},
  /* NeoPixel */
  {kIoLedStatusPin, OUTPUT}
};


 io_button_t io_buttons[kIoButtonAmmount] = {
  {kIoButtonPin, HIGH, HIGH, 0, 0}
};

//  const uint8_t io_analog_pins[kIoAnalogInAmmount] = { kIoPotPin };


 const unsigned long kIoDebounceDelay = 50;