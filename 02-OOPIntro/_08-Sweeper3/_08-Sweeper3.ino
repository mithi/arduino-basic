
#include "SimpleLibrary.h"

Sweeper sweeper;
Metronome metronome;

void setup(){
  sweeper.Format(8, 0, 2, BACKANDFORTH);
  metronome.Format(250);
  Serial.begin(115200);
}

void loop(){
 sweep();
}

void sweep(){
  if (metronome.Tick())
    Serial.print(sweeper.Next(1));
}

