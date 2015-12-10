
#include "SimpleLibrary.h"

DigitalOutput relay;
Metronome metronome;

void setup() {
  
  metronome.Format(3000);
  relay.Format(0);
}

void loop() {
  
  if(metronome.Tick())
    relay.Toggle();
}

