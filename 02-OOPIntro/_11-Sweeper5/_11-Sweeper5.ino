
#include "SimpleLibrary.h"

Sweeper sweeper;
AnalogLED led;
TimingManager interval;

void setup(){
  led.New(9);
  interval.New(10);
  sweeper.New(0, 100, BACKANDFORTH);
}

void loop(){
 led.NewBrightness(sweeper.Update(interval.IsTimeToUpdate()));
}

