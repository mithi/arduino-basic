
#include "SimpleLibrary.h"

Sweeper sweeper; 
Buzzer buzzer;
AnalogLED led;

int f1 = 3000;
int f2 = 3500;
int f = 0;

void setup() {
  sweeper.New(f1, f2, BACKANDFORTH); 
  buzzer.New(13, 1.3, 1000);
  led.New(6);
}

void loop() {
  f = sweeper.Next(1); 
  buzzer.Play(f, 4, 2);
  led.NewBrightness(map(f, f1, f2, 0, 100));
  delayMicroseconds(1000);
}

