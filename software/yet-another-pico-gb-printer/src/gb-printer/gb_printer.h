#ifndef __GB_PRINTER__H__
#define __GB_PRINTER__H__

#include "gb_printer_config.h"
#include <Arduino.h>

#include "gbp_pkt.h"
#include "gbp_serial_io.h"

#include "io_config.h"

#include "hardware/gpio.h"

#define GBP_SO_PIN kIoGbpSoPin
#define GBP_SI_PIN kIoGbpSiPin
#define GBP_SC_PIN kIoGbpScPin

#endif  //!__GB_PRINTER__H__