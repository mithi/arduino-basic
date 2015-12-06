
#include "SimpleLibrary.h"

Sweeper sweeper; 
Buzzer buzzer;
AnalogOutput led;

int f1 = 3000;
int f2 = 4500;

void setup() {
  sweeper.New(f1, f2, 1, BACKANDFORTH); 
  buzzer.New(13, 1.3, 1000);
}

void loop() {
  buzzer.Play(sweeper.Next(1), 3, 1);
}

/*
 *  sweeper.New(f1, f2, NORMAL);
 *  sweeper.New(f2, f1, NORMAL);
 *  change f1 and f2 to f1 = 500 f2 =100 or something else
 *  try buzzer.Play(f, 3, 1); 
 *  buzzer.Play(f, soundPeriod = 4, pause = 2); in milliseconds
 * 
 */
 

