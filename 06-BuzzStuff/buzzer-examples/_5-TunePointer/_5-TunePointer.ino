
#include "SimpleLibrary.h"
#include "Tunes.h"

Buzzer buzzer; 
Sweeper sweeper;
Button button;

int x = 0;

int *currentSong;
int *currentSongTempo;
int currentSongSize; 

void setup() {
  
  buzzer.New(13, 1.3, 1000);
  
  currentSong = superMarioTune;
  currentSongTempo = superMarioTuneTempo; 
  currentSongSize = superMarioTuneSize;
  
  sweeper.New(0, currentSongSize, NORMAL);
}

void loop() {

  buzzer.PlayNote(*(currentSong+x), float(*(currentSongTempo+x)));
  x = sweeper.Update(1);
}

