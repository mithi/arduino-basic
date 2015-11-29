
#include "SimpleLibrary.h"

Sweeper sweeper; 
Buzzer buzzer;
AnalogLED led;

int f1 = 3000;
int f2 = 4500;
int f = 0;

void setup() {
  sweeper.New(f1, f2, BACKANDFORTH); 
  buzzer.New(13, 1.3, 1000);
}

void loop() {
  f = sweeper.Update(1); 
  buzzer.Play(f, 4, 2);
}

/*
 *  sweeper.New(f1, f2, NORMAL);
 *  sweeper.New(f2, f1, NORMAL);
 *  change f1 and f2 to f1 = 500 f2 =100 or something else
 *  try buzzer.Play(f, 3, 1); 
 *  buzzer.Play(f, soundPeriod = 3, Pause = 1); int milliseconds
 *  
 */
 

