
#include "SimpleLibrary.h"
#include "Tunes.h"

Buzzer buzzer; 
Sweeper sweeper;

void setup() {
  buzzer.Format(13, 1.3, 1000);
  sweeper.Format(0, superMarioTuneSize, 1, NORMAL);
} 

void loop() {                     
  int x = sweeper.Next(1);
  buzzer.PlayNote(superMarioTune[x], float(superMarioTuneTempo[x]));
}

//try underworld, starspangled banner
