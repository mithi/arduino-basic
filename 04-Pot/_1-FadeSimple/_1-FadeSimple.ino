
#include "SimpleLibrary.h"

AnalogInput pot; 
AnalogOutput led;

void setup() {
  pot.New(A5);
  led.New(11);
}

void loop() {
  led.Set(pot.MappedValue(0, 100));
}


