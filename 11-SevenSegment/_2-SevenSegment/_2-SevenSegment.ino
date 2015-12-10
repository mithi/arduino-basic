
#include "SimpleLibrary.h"

Metronome metronome;
Sweeper toggler;
SevenSegment SSD;

int pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void setup(){
  metronome.Format(500);
  toggler.Format(0, 18, 1, BACKANDFORTH);
  SSD.Format(pins, COMMONANODE); 
}

void loop(){
  int x = toggler.Next(metronome.Tick());  
  x % 2 == 0 ? SSD.Display(x/2) : SSD.Display(OFF); 
}

