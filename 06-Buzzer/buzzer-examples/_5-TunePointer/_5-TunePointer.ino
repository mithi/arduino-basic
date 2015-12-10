
#include "SimpleLibrary.h"
#include "Tunes.h"

Buzzer buzzer; 
Sweeper sweeper;
Button button;

int x = 0;

int *currentSong;
byte *currentSongTempo;
byte currentSongSize; 

void setup() {
  
  buzzer.Format(13, 1.3, 1000);
  
  currentSong = superMarioTune;
  currentSongTempo = superMarioTuneTempo; 
  currentSongSize = superMarioTuneSize;
  
  sweeper.Format(0, currentSongSize, 1, NORMAL);
}

void loop() {

  buzzer.PlayNote(*(currentSong+x), float(*(currentSongTempo+x)));
  x = sweeper.Next(1);
}

