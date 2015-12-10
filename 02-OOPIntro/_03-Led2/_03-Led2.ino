
#include "SimpleLibrary.h"

DigitalOutput led;

void setup() {
  led.Format(11);
}


void loop() {
  led.Toggle();
  delay(500);
}

