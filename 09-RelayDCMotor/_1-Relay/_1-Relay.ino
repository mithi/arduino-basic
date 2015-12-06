
#include "SimpleLibrary.h"

DigitalOutput relay;
Metronome metronome;

void setup() {
  
  metronome.New(3000);
  relay.New(0);
}

void loop() {
  
  if(metronome.Tick())
    relay.Toggle();
}

