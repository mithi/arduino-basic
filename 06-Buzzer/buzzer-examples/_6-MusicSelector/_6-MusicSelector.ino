
#include "SimpleLibrary.h"
#include "Tunes.h"

Buzzer buzzer; 
Sweeper sweeper;
Sweeper toggler;
Button button;

int x = 0;
int m = 0;
const int tune_count = 3;

struct melody current_tune;

void setup() {
  
  buzzer.Format(13, 1.3, 1000);
  button.Format(0, 50);
  
  current_tune = super_mario;

  sweeper.Format(0, current_tune.size-1, 1, NORMAL);
  toggler.Format(0, tune_count, 1, NORMAL);

}

void loop() {

  if(button.JustPressed())
    nextMusic();
  
  buzzer.PlayNote(current_tune.tune[x], float(current_tune.tempo[x]));  
  x = sweeper.Next(1);
}

void nextMusic(){
  
  m = toggler.Next(1);
  
  if (m == 0)
    current_tune = super_mario;
    
  if (m == 1)
    current_tune = underworld;

  if (m == 2)
    current_tune = star_spangled_banner;
  
  sweeper.Format(0, current_tune.size-1, 1, NORMAL);
}

