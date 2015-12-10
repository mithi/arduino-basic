
#include "SimpleLibrary.h"

Metronome metronome;

void setup() {
  metronome.Format(500);
  Serial.begin(115200);
}


void loop() {
  if(metronome.Tick())
    Serial.println("hey!");
}

