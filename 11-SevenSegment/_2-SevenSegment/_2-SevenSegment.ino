
#include "SimpleLibrary.h"

TimingManager timing;
Sweeper toggler;
SevenSegment SSD;

int pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void setup(){
  timing.New(500);
  toggler.New(0, 21, BACKANDFORTH);
  SSD.New(pins, COMMONANODE ); 
}

void loop(){
  int x = toggler.Next(timing.Tick());  
  x % 2 == 0 ? SSD.Display(x/2) : SSD.Display(OFF); 
}

