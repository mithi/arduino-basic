
#include "SimpleLibrary.h"

Sweeper sweeper; 
Buzzer buzzer;
AnalogOutput led;
Metronome metronome; 

int f1 = 3000;
int f2 = 3500;
int f = 0;
int dwell = 5; //try dwell = 1, 5, or 10

void setup() {
  sweeper.New(f1, f2, 1, NORMAL); 
  buzzer.New(13, 1.3, 1000);
  metronome.New(dwell);
}

void loop() {
  f = sweeper.Next(metronome.Tick()); 
  buzzer.Play(f, 3, 0);
}

