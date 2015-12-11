
#include "SimpleLibrary.h"
#include "Tunes.h"

Buzzer buzzer; 
Sweeper sweeper;

void setup() {
  buzzer.Format(13, 1.3, 1000);
  sweeper.Format(0, star_spangled_banner.size, 1, NORMAL);
} 

void loop() {                     
  int x = sweeper.Next(1);
  buzzer.PlayNote(star_spangled_banner.tune[x], float(star_spangled_banner.tempo[x]));
}

//try super_mario, underworld, star_spangled_banner
