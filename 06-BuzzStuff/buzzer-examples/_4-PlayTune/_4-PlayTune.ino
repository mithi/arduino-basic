
#include "SimpleLibrary.h"
#include "Tunes.h"

Buzzer buzzer; 
Sweeper sweeper;

void setup() {
  buzzer.New(13, 1.3, 1000);
  sweeper.New(0, superMarioTuneSize, NORMAL);
}

void loop() {
  int x = sweeper.Update(1);
  buzzer.PlayNote(superMarioTune[x], float(superMarioTuneTempo[x]));
}

//try underworld, starspangled banner
