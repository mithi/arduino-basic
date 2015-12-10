
#include "SimpleLibrary.h"

DigitalOutput led;
Metronome metronome;

void setup() {
  metronome.Format(250);
  led.Format(11);
}


void loop() {
  if(metronome.Tick())
    led.Toggle();
}

