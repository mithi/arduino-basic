
#include "SimpleLibrary.h"

AnalogInput pot; 
DigitalOutput led;
Metronome metronome;

void setup() {
  
  pot.New(A5);
  led.New(11);
}

void loop() {  

  metronome.SetInterval(pot.RawValue());
  
  if (metronome.Tick())
    led.Toggle();
}

