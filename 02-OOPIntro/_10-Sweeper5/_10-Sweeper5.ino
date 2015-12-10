
#include "SimpleLibrary.h"

Sweeper sweeper;
AnalogOutput led;
Metronome metronome;

void setup(){
  led.Format(11);
  metronome.Format(10);
  sweeper.Format(0, 100, 1, BACKANDFORTH);
}

void loop(){
 led.Set(sweeper.Next(metronome.Tick()));
}

