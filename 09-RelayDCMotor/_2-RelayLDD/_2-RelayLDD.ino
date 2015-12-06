
#include "SimpleLibrary.h"

DigitalOutput` relay;
AnalogSensor LDD;

void setup() { 
  relay.New(0);
  LDD.New(A5, INPUT_PULLUP, 500, HIGH, 1, 0); 
}

void loop() { 
  LDD.IsTrue() ? relay.On() : relay.Off();
}

