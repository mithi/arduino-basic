
#include "SimpleLibrary.h"

RGB rgb;
AnalogInput rPot, gPot, bPot;
int x = 250; //maxbrightness

void setup() {
  rgb.Format(11,10,9);
  rPot.Format(A5);
  gPot.Format(A4);
  bPot.Format(A3);
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

