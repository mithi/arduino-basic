
#include "SimpleLibrary.h"

AnalogInput pot; 
AnalogOutput led;

void setup() {
  pot.Format(A5);
  led.Format(11);
}

void loop() {
  led.Set(pot.MappedValue(0, 100));
}


