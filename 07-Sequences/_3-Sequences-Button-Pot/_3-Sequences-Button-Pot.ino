
#include "SimpleLibrary.h"

Button button;
AnalogInput pot;
Sweeper toggler;

Metronome metronome;
Sequencer sequence;
LedsManager leds;

int ledPins[] = {11,10,9,6,5,3};

void setup() {
  
  pot.New(A5);
  button.New(0, 50);
  toggler.New(0, 5, 1, NORMAL);
  
  metronome.New(100);
  leds.New(ledPins);
  sequence.New(&leds);
  
  sequence.Start(STAIRSUP);
}

void loop() {

  sequence.Update(metronome.Tick());
  metronome.SetInterval(pot.MappedValue(50,300));
  
  if(button.JustReleased())
    sequence.Start(toggler.Next(1));
}

