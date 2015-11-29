
#include "SimpleLibrary.h"

Relay relay;
TimingManager toggleTiming;

void setup() {
  
  toggleTiming.New(3000);
  relay.New(0);
}

void loop() {
  
  if(toggleTiming.IsTimeToUpdate())
    relay.Toggle();
}
