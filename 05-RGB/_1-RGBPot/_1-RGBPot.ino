
#include "SimpleLibrary.h"

RGB rgb;
Potentiometer rPot, gPot, bPot;
int x = 250; //maxbrightness

void setup() {
  rgb.New(11,10,9);
  rPot.New(A5);
  gPot.New(A4);
  bPot.New(A3);
}

void loop() {
  rgb.ColorRaw(rPot.MappedValue(0,x), gPot.MappedValue(0,x), bPot.MappedValue(0,x));
}

/*

  int r = rPot.MappedValue(0,x);
  int g = gPot.MappedValue(0,x);
  int b = bPot.MappedValue(0,x);
  rgb.ColorRaw(r, g, b);

*/

