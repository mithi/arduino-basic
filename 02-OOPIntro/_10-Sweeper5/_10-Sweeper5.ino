
#include "SimpleLibrary.h"

Sweeper sweeper;
AnalogOutput led;
Metronome metronome;

void setup(){
  led.New(11);
  metronome.New(10);
  sweeper.New(0, 100, 1, BACKANDFORTH);
}

void loop(){
 led.Set(sweeper.Next(metronome.Tick()));
}

