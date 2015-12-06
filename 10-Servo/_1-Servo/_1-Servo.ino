
#include "SimpleLibrary.h"
#include <Servo.h>

Servo servo;
AnalogInput pot;

void setup() {
  servo.attach(9);
  pot.New(A5);
}

void loop() {
  servo.write(pot.MappedValue(0,180));
  delay(10);
}

