
#include "SimpleLibrary.h"

Sweeper sweeper;

void setup(){
  sweeper.New(4, 0, BACKANDFORTH);
  Serial.begin(9600);
}

void loop(){
  Serial.print(sweeper.Next(1));
  delay(250);
}

/*
 * sweeper.New(0, 4, NORMAL);
 * sweeper.New(4, 0, NORMAL);
 * 
 */
