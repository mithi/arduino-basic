
#include "SimpleLibrary.h"

int ledPins[] = {11,10,9,6,5,3};

Sweeper toggler;
Metronome metronome;
Sequencer sequence;
LedsManager leds;

Button button;
AnalogInput pot1, pot2;

void setup() {
  
  pot1.Format(A5);
  pot2.Format(A4);
  button.Format(0, 50);
  
  metronome.Format(100);
  leds.Format(ledPins);
  toggler.Format(0, 5, 1, NORMAL); 
  sequence.Format(&leds);
  
  sequence.Start(STAIRSUP);
}

void loop() {

  if(button.JustReleased())
      sequence.Start(toggler.Next(1));  
    
  metronome.SetInterval(pot1.MappedValue(50,300));
  leds.SetBrightness(pot2.MappedValue(0, 255));

  sequence.Update(metronome.Tick());
}

