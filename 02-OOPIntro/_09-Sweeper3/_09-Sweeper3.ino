
#include "SimpleLibrary.h"

Sweeper sweeper;
TimingManager interval;

void setup(){
  sweeper.New(4, 0, BACKANDFORTH);
  interval.New(500);
  Serial.begin(9600);
}

void loop(){
 sweep();
}

void sweep(){
  if (interval.Tick())
    Serial.print(sweeper.Next(1));
}

