

#include "oled.h"

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(u8g2_cb_r3);  // U8g2 display setup
// U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, kIoPinOledScl, kIoPinOledSda);  // Somehow this doesent work

void OledInit(void) {
  u8g2.begin(); // Initialize U8g2
  u8g2.clearBuffer(); // Clear the display buffer
  u8g2.setDrawColor(1); // Set color to white
  u8g2.setDisplayRotation
  OledDrawTest();
}


void OledDrawTest(void) {
  u8g2.clearBuffer(); // Clear the display buffer
  u8g2.sendBuffer(); // Send the buffer to the display
}