
#include "SimpleLibrary.h"

AnalogInput pot; 
DigitalOutput led;

void setup() {
  pot.Format(A5);
  led.Format(11);
}

void loop() {
  led.Toggle();
  delay(pot.RawValue());
}


