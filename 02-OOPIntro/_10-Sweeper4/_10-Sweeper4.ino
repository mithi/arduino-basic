
#include "SimpleLibrary.h"

Sweeper sweeper;
TimingManager interval;
int oldx = 0;

void setup(){
  sweeper.New(4, 0, BACKANDFORTH);
  interval.New(100);
  Serial.begin(9600);
}

void loop(){
 sweep();
}

void sweep(){
  
  int x = sweeper.Next(interval.Tick());

  if(x == oldx){
    Serial.print(x);
  }else{
    Serial.println("NEXT NUMBER!");
    oldx = x;
  }
}

