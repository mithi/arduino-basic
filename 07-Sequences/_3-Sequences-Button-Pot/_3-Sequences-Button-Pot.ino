
#include "SimpleLibrary.h"

Button button;
Potentiometer pot;
Sweeper toggler;

TimingManager timing;
Sequencer sequence;
LedsManager leds;

int ledPins[] = {11,10,9,6,5,3};
byte sequenceType;

void setup() {
  
  pot.New(A5);
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

  timing.NewInterval(pot.MappedValue(50,300));
  
  if(button.JustReleased())
    sequence.Start(toggler.Next(1));
}

