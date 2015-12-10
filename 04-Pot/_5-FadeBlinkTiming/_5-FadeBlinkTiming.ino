
#include "SimpleLibrary.h"

AnalogInput pot1, pot2; 
AnalogOutput led;
Metronome metronome;
bool state = 0;

void setup() {
  
  pot1.Format(A5);
  pot2.Format(A4);
  led.Format(11);
}

void loop() {
   
  metronome.SetInterval(pot1.RawValue());

  if (metronome.Tick()){
    state == HIGH ? led.Set(pot2.MappedValue(0, 255)) : led.Set(0);
    state = !state;
  }
}
