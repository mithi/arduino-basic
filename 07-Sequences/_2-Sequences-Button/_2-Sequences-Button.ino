
#include "SimpleLibrary.h"

Button button;
Sweeper toggler;

Metronome metronome;
Sequencer sequence;
LedsManager leds;

int ledPins[] = {11,10,9,6,5,3};

void setup() {
  
  button.New(0, 50);
  toggler.New(0, 5, 1, NORMAL);
  
  metronome.New(100);
  leds.New(ledPins);
  sequence.New(&leds);
  
  sequence.Start(STAIRSUP);
}

void loop() {

  sequence.Update(metronome.Tick());
  
  if(button.JustReleased())
    sequence.Start(toggler.Next(1));
}

