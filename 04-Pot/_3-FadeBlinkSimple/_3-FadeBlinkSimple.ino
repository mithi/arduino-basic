
#include "SimpleLibrary.h"

AnalogInput pot1, pot2;
AnalogOutput led;

void setup() {

  pot1.Format(A4);
  pot2.Format(A5);
  led.Format(11);
}

void loop() {
  led.Set(pot1.MappedValue(0, 250));
  delay(pot2.RawValue());
  led.Set(0);
  delay(pot2.RawValue());
}


