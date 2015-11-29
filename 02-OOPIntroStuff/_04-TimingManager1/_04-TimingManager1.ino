
#include "SimpleLibrary.h"

TimingManager interval;

void setup() {
  interval.New(500);
  Serial.begin(9600);
}


void loop() {
  if(interval.IsTimeToUpdate())
    Serial.println("hey!");
}

