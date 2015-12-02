
#include "SimpleLibrary.h"

RGB rgb;
Sweeper sweeper;
TimingManager interval;

int maxCount = 24; // max color constant value times two

void setup() {
  rgb.New(11,10,9);
  sweeper.New(0, maxCount, NORMAL);
  interval.New(500);
}

void loop() {
  blinkingColors();
}

void blinkingColors(){
  int x = sweeper.Next(interval.Tick());
  int r = x % 2;
  x /= 2;
  
  r == 1 ? rgb.Color(x) : rgb.ColorRaw(0,0,0);
}

