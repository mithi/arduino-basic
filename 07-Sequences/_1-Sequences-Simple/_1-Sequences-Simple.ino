
#include "SimpleLibrary.h"

int ledPins[] = {11,10,9,6,5,3};

TimingManager ledsTiming;
SequenceStateUpdater sequence;
LedsManager leds;

void setup() {
  
  ledsTiming.New(100);
  leds.New(ledPins);
  sequence.New(&leds);

  sequence.Start(STAIRSDOWN);
}

void loop() {
  
  sequence.Update(ledsTiming.IsTimeToUpdate());
}

