#ifndef __IO_CONFIG__H__
#define __IO_CONFIG__H__

#include <stdint.h>

#define kIoButtonAmmount 1
#define kIoPinAmmountSize 1
#define kIoAnalogInAmmount 1

typedef struct io_pin_config {
  uint8_t pin_number;
  uint8_t pin_mode;
} io_pin_config_t;

typedef struct  {
  uint8_t pin;
  uint8_t state;
  uint8_t lastState;
  unsigned long lastDebounceTime;
  uint8_t activated;
} io_button_t;


typedef enum {
  kIoButtonTop = 0,
  kIoButtonMid = 1,
  kIoButtonBot = 2
} io_button_e;

typedef enum {
  kIoPot = 0,
} io_analog_in_e;


/* externs */
extern const uint8_t kIoPinI2c0Sda;
extern const uint8_t kIoPinI2c0Scl;
extern const uint8_t kIoPinSpi1Miso;
extern const uint8_t kIoPinSpi1Mosi;
extern const uint8_t kIoPinSpi1Sck;
extern const uint8_t kIoPinSpi1Cs;
extern const uint8_t kIoPinOledSda;
extern const uint8_t kIoPinOledScl;
extern const uint8_t kIoButtonPin;
extern const uint8_t kIoGbpSoPin;
extern const uint8_t kIoGbpSiPin;
extern const uint8_t kIoGbpScPin;
extern const uint8_t kIoLedStatusPin; 
extern const uint8_t kIoRngPin;
extern io_pin_config_t io_pin_config[kIoPinAmmountSize];
extern io_button_t io_buttons[kIoButtonAmmount];
extern const unsigned long kIoDebounceDelay;
#endif  //!__IO_CONFIG__H__