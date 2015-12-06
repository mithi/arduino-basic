
#include "SimpleLibrary.h"

Sweeper sweeper;
AnalogOutput led;

void setup(){
  led.New(11);
  sweeper.New(0, 120, 1, BACKANDFORTH);
}

void loop(){
 led.Set(sweeper.Next(1));
 delay(10);
}

