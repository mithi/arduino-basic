
#include "SimpleLibrary.h"

RGB rgb;
Sweeper sweeper;
Metronome metronome;
int maxCount = 12; 

void setup() {
  rgb.Format(11,10,9);
  sweeper.Format(0, maxCount, 1, NORMAL);
  metronome.Format(500);
}

void loop() {
  rgb.Color(sweeper.Next(metronome.Tick()));
}


