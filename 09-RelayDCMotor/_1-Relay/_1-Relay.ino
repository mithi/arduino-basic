
#include "SimpleLibrary.h"

Relay relay;
TimingManager toggleTiming;

void setup() {
  
  toggleTiming.New(3000);
  relay.New(0);
}

void loop() {
  
  if(toggleTiming.Tick())
    relay.Toggle();
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
