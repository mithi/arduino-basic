
#include "SimpleLibrary.h"
#include "Tunes.h"

Buzzer buzzer; 
Sweeper sweeper;
Sweeper toggler;
Button button;

int x = 0;
int m = 0;
int tuneCount = 2;

int *currentTune;
int *currentTuneTempo;
int currentTuneSize; 

void setup() {
  
  buzzer.New(13, 1.3, 1000);
  button.New(0, 50);
  
  currentTune = underworldTune;
  currentTuneTempo = underworldTuneTempo; 
  currentTuneSize = underworldTuneSize;

  sweeper.New(0, currentTuneSize, NORMAL);
  toggler.New(0, tuneCount-1, NORMAL);

}

void loop() {

  button.Update();

  if(button.JustPressed())
    nextMusic();
  
  buzzer.PlayNote(*(currentTune+x), float(*(currentTuneTempo+x)));
  
  x = sweeper.Update(1);
}

void nextMusic(){
  
  m = toggler.Update(1);
  
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
  
  sweeper.New(0, currentTuneSize, NORMAL);
}

