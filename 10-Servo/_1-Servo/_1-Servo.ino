
#include "SimpleLibrary.h"
#include <Servo.h>

Servo servo;
Sweeper sweeper;
TimingManager timing; 

void setup() {
  servo.attach(9);
  sweeper.New(0, 180, BACKANDFORTH);
  timing.New(15);
}

void loop() {
  servo.write(sweeper.Update(timing.IsTimeToUpdate()));
}


