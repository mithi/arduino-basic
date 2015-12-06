
#include "SimpleLibrary.h"

Metronome metronome;

void setup() {
  metronome.New(500);
  Serial.begin(115200);
}


void loop() {
  if(metronome.Tick())
    Serial.println("hey!");
}

