#include "SimpleLibrary.h"

Potentiometer pot1, pot2;
AnalogLED led;

void setup() {

  pot1.New(A4);
  pot2.New(A5);
  led.New(11);
}

void loop() {
  led.NewBrightness(pot1.MappedValue(0, 250));
  delay(pot2.RawValue());
  led.NewBrightness(0);
  delay(pot2.RawValue());
}


