
#include "SimpleLibrary.h"

SevenSegment SSD;

int pins[8] = { 0, 1, 2, 3, 4, 5, 6, 7};
int A[8] = { 1, 1, 1, 1, 1, 0, 1, 0};

void setup() {
  SSD.Format(pins, COMMONANODE); 
}

void loop() {
  SSD.SetRaw(A);
}

