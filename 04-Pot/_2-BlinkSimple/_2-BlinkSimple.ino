
#include "SimpleLibrary.h"

AnalogInput pot; 
DigitalOutput led;

void setup() {
  pot.New(A5);
  led.New(11);
}

void loop() {
  led.Toggle();
  delay(pot.RawValue());
}


