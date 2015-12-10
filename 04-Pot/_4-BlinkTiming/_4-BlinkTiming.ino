
#include "SimpleLibrary.h"

AnalogInput pot; 
DigitalOutput led;
Metronome metronome;

void setup() {
  
  pot.Format(A5);
  led.Format(11);
}

void loop() {  

  metronome.SetInterval(pot.RawValue());
  
  if (metronome.Tick())
    led.Toggle();
}

