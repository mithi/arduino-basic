
#include "SimpleLibrary.h"

RGB rgb;
Sweeper sweeper;
Metronome metronome;
int maxCount = 12; 

void setup() {
  rgb.New(11,10,9);
  sweeper.New(0, maxCount, 1, NORMAL);
  metronome.New(500);
}

void loop() {
  rgb.Color(sweeper.Next(metronome.Tick()));
}


