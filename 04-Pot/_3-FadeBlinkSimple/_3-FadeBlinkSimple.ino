
#include "SimpleLibrary.h"

AnalogInput pot1, pot2;
AnalogOutput led;

void setup() {

  pot1.New(A4);
  pot2.New(A5);
  led.New(11);
}

void loop() {
  led.Set(pot1.MappedValue(0, 250));
  delay(pot2.RawValue());
  led.Set(0);
  delay(pot2.RawValue());
}


