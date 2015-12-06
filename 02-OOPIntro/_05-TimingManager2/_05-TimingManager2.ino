
#include "SimpleLibrary.h"

DigitalOutput led;
Metronome metronome;

void setup() {
  metronome.New(250);
  led.New(11);
}


void loop() {
  if(metronome.Tick())
    led.Toggle();
}

