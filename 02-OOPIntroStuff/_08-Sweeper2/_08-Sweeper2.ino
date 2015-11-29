
#include "SimpleLibrary.h"

Sweeper sweeper;
AnalogLED led;

void setup(){
  led.New(9);
  sweeper.New(0, 100, BACKANDFORTH);
}

void loop(){
 led.NewBrightness(sweeper.Update(1));
 delay(10);
}

