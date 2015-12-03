
#include "SimpleLibrary.h"

Relay relay;
AnalogSensor LDD;

void setup() {
  
  relay.New(0);
  LDD.New(A5, INPUT_PULLUP, 500, HIGH, 1, 0); 
}

void loop() {
  
  LDD.IsTrue() ? relay.SwitchPower() : relay.SwitchDefault();
}


/* ******************************************************
 * 
 * If you take a look at the Relay class and the DigitalLED class, they are significantly similar, because they
 * are essentially the same thing, this is an interesting observation for me, as they just both just digital outputs. 
 * You can consider just creating a single DigitalOutput class and declaring the instances as:
 * DigitalOutput led;
 * DigitalOutput relay;
 * instead of having two separate classes Relay and DigitalLED.
 * I'm considering merging these two classes as of the moment, but that requires
 * rewriting the sample codes that use them (and that's a lot!), and maybe the effort is not worth it!
 * 
 * ******************************************************/
