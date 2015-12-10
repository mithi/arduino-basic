
#include "SimpleLibrary.h"

Sweeper sweeper;
AnalogOutput led;

void setup(){
  led.Format(11);
  sweeper.Format(0, 120, 1, BACKANDFORTH);
}

void loop(){
 led.Set(sweeper.Next(1));
 delay(10);
}

