
#include "SimpleLibrary.h"
#include "Tunes.h"

Buzzer buzzer; 
Sweeper sweeper;
Sweeper toggler;
Button button;

int x = 0;
int m = 0;
const int tuneCount = 2;

int *currentTune;
byte *currentTuneTempo;
byte currentTuneSize; 

void setup() {
  
  buzzer.Format(13, 1.3, 1000);
  button.Format(0, 50);
  
  currentTune = underworldTune;
  currentTuneTempo = underworldTuneTempo; 
  currentTuneSize = underworldTuneSize;

  sweeper.Format(0, currentTuneSize, 1, NORMAL);
  toggler.Format(0, tuneCount-1, 1, NORMAL);

}

void loop() {

  if(button.JustPressed())
    nextMusic();
  
  buzzer.PlayNote(*(currentTune+x), float(*(currentTuneTempo+x)));
  
  x = sweeper.Next(1);
}

void nextMusic(){
  
  m = toggler.Next(1);
  
  if (m == 0){
    currentTune = underworldTune;
    currentTuneTempo = underworldTuneTempo; 
    currentTuneSize = underworldTuneSize;
  }

  if (m == 1){
    currentTune = superMarioTune;
    currentTuneTempo = superMarioTuneTempo; 
    currentTuneSize = superMarioTuneSize;
  }
  
  sweeper.Format(0, currentTuneSize-1, 1, NORMAL);
}

