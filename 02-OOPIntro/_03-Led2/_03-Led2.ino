
#include "SimpleLibrary.h"

DigitalOutput led;

void setup() {
  led.New(11);
}


void loop() {
  led.Toggle();
  delay(500);
}

