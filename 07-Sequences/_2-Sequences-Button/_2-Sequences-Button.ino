
#include "SimpleLibrary.h"

Button button;
Sweeper toggler;

Metronome metronome;
Sequencer sequence;
LedsManager leds;

int ledPins[] = {11,10,9,6,5,3};

void setup() {
  
  button.Format(0, 50);
  toggler.Format(0, 5, 1, NORMAL);
  
  metronome.Format(100);
  leds.Format(ledPins);
  sequence.Format(&leds);
  
  sequence.Start(STAIRSUP);
}

void loop() {

  sequence.Update(metronome.Tick());
  
  if(button.JustReleased())
    sequence.Start(toggler.Next(1));
}

