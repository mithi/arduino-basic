
#include "SimpleLibrary.h"

DigitalOutput` relay;
AnalogSensor LDD;

void setup() { 
  relay.Format(0);
  LDD.Format(A5, INPUT_PULLUP, 500, HIGH, 1, 0); 
}

void loop() { 
  LDD.IsTrue() ? relay.On() : relay.Off();
}

