
#include "SimpleLibrary.h"
#include "Tunes.h"

Buzzer buzzer; 
Sweeper sweeper;
Button button;

int x = 0;

struct melody current_tune;

void setup() {
  
  buzzer.Format(13, 1.3, 1000);
  current_tune = super_mario;
  sweeper.Format(0, current_tune.size, 1, NORMAL);
}

void loop() {

  buzzer.PlayNote(current_tune.tune[x], float(current_tune.tempo[x]));
  x = sweeper.Next(1);
}

