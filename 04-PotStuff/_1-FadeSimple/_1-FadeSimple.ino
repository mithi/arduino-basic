
#include "SimpleLibrary.h"

Potentiometer pot; 
AnalogLED led;

void setup() {
  pot.New(A5);
  led.New(11);
}

void loop() {
  led.NewBrightness(pot.MappedValue(0, 100));
}


