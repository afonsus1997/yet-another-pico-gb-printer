#include <Arduino.h>
#include "main.h"


void setup() {
  Serial.begin(115200);
  Serial.println("Starting up...");

  IoInit();
  LedInit();
  OledInit();
}

void loop(){
  while(1){
    IoReadButtons();
  }
}