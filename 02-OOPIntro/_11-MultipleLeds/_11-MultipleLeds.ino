
#include "SimpleLibrary.h"

DigitalOutput led[3];
Metronome metronome[3];
Sweeper toggler;
const int DELAY = 250;
int x;

void setup() {
  
  toggler.Format(0, 2, 1, NORMAL);
  
  metronome[0].Format(DELAY);
  metronome[1].Format(2*DELAY);
  metronome[2].Format(4*DELAY);

  led[0].Format(3);
  led[1].Format(5);
  led[2].Format(6);
}


void loop() {
  x = toggler.Next(1);
  if(metronome[x].Tick())
    led[x].Toggle();
}

