
#include "SimpleLibrary.h"

int ledPins[] = {11,10,9,6,5,3};

Sweeper toggler;
Metronome metronome;
Sequencer sequence;
LedsManager leds;

Button button;
AnalogInput pot1, pot2;

void setup() {
  
  pot1.New(A5);
  pot2.New(A4);
  button.New(0, 50);
  
  metronome.New(100);
  leds.New(ledPins);
  toggler.New(0, 5, 1, NORMAL); 
  sequence.New(&leds);
  
  sequence.Start(STAIRSUP);
}

void loop() {

  if(button.JustReleased())
      sequence.Start(toggler.Next(1));  
    
  metronome.SetInterval(pot1.MappedValue(50,300));
  leds.SetBrightness(pot2.MappedValue(0, 255));

  sequence.Update(metronome.Tick());
}

