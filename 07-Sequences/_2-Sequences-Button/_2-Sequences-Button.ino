
#include "SimpleLibrary.h"

Button button;
Sweeper toggler;

TimingManager timing;
Sequencer sequence;
LedsManager leds;

int ledPins[] = {11,10,9,6,5,3};
byte sequenceType;

void setup() {
  
  button.New(0, 50);
  toggler.New(0, 5, NORMAL);
  
  timing.New(100);
  leds.New(ledPins);
  sequence.New(&leds);
  
  sequence.Start(STAIRSUP);
}

void loop() {

  sequence.Update(timing.Tick());
  button.Update();
  
  if(button.JustReleased())
    sequence.Start(toggler.Next(1));
}

