
#include "SimpleLibrary.h"

Sweeper sweeper;
Metronome metronome;
int oldx = 0;

void setup(){
  sweeper.Format(4, 0, 1, BACKANDFORTH);
  metronome.Format(100);
  Serial.begin(9600);
}

void loop(){
 sweep();
}

void sweep(){
  
  int x = sweeper.Next(metronome.Tick());

  if(x == oldx){
    Serial.print(x);
  }else{
    Serial.println(" NEXT NUMBER!");
    oldx = x;
  }
}

