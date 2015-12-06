
#include "SimpleLibrary.h"

DigitalOutput led[3];
Metronome metronome[3];
Sweeper toggler;
const int DELAY = 250;
int x;

void setup() {
  
  toggler.New(0, 2, 1, NORMAL);
  
  metronome[0].New(DELAY);
  metronome[1].New(2*DELAY);
  metronome[2].New(4*DELAY);

  led[0].New(3);
  led[1].New(5);
  led[2].New(6);
}


void loop() {
  x = toggler.Next(1);
  if(metronome[x].Tick())
    led[x].Toggle();
}

