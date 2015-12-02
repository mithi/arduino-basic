
#include "SimpleLibrary.h"

Sweeper sweeper;
AnalogLED led;

void setup(){
  led.New(11);
  sweeper.New(0, 100, BACKANDFORTH);
}

void loop(){
 led.NewBrightness(sweeper.Next(1));
 delay(10);
}

