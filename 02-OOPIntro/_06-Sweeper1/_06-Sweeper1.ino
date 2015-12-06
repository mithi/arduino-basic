
#include "SimpleLibrary.h"

Sweeper sweeper;

void setup(){
  sweeper.New(0, 4, 1, BACKANDFORTH);
  Serial.begin(115200);
}

void loop(){
  Serial.print(sweeper.Next(1));
  delay(250);
}

/*
 * sweeper.New(0, 4, 1, NORMAL);
 * sweeper.New(4, 0, 1, NORMAL);
 * sweeper.New(0, 8, 2, NORMAL);
 * sweeper.New(8, 0, 2, NORMAL);
 * sweeper.New(8, 0, 2, BACKANDFORTH);
 * 
 * Note, that the implementation of Sweeper doesn't 
 * catch objects with steps that don't 
 * end on the endNumber specified based on the startNumber
 * in essence, sweeper.New(8, 0, 3, BACKANDFORTH); will increment as follows
 * 8, 5, 2,-1...2, 5, 8
 * You can try to implement it yourself! :) 
 * 
 */
