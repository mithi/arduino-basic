
#include "SimpleLibrary.h"

DigitalLED led;
TimingManager interval;

void setup() {
  interval.New(250);
  led.New(11);
}


void loop() {
  if(interval.Tick())
    led.Toggle();
}

