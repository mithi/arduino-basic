
#include "SimpleLibrary.h"

DigitalLED led[3];
TimingManager interval[3];
const int DELAY = 250;

void setup() {
  
  interval[0].New(DELAY);
  interval[1].New(2*DELAY);
  interval[2].New(4*DELAY);

  led[0].New(9);
  led[1].New(10);
  led[2].New(11);
}


void loop() {
  updateLeds();
}

void updateLeds(){

  for(int x=0; x<3; x++){
    if(interval[x].IsTimeToUpdate())
      led[x].Toggle();
  }
}

