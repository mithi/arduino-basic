
#include "SimpleLibrary.h"

int ledPins[] = {11,10,9,6,5,3};
Metronome metronome;
Sequencer sequence;
LedsManager leds;

void setup() {
  
  metronome.New(100);
  leds.New(ledPins);
  sequence.New(&leds);

  sequence.Start(STAIRS);
}

void loop() {
  
  sequence.Update(metronome.Tick());
}

