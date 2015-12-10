
#include "SimpleLibrary.h"

Sweeper sweeper; 
Buzzer buzzer;
AnalogOutput led;

int f1 = 3000;
int f2 = 3500;
int f = 0;

void setup() {
  sweeper.Format(f1, f2, 1, BACKANDFORTH); 
  buzzer.Format(13, 1.3, 1000);
  led.Format(6);
}

void loop() {
  f = sweeper.Next(1); 
  buzzer.Play(f, 4, 2);
  led.Set(map(f, f1, f2, 0, 150));
  delay(1);
}

