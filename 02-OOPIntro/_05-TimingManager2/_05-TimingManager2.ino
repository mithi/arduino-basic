
#include "SimpleLibrary.h"

DigitalLED led;
TimingManager interval;

void setup() {
  interval.New(250);
  led.New(9);
}


void loop() {
  if(interval.IsTimeToUpdate())
    led.Toggle();
}

