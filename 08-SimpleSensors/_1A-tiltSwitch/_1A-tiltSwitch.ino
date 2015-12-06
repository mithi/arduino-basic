
#include "SimpleLibrary.h"

Metronome metronome;
DigitalSensor tiltSwitch;
bool tilted = 0;

void setup() {

  tiltSwitch.New(3, INPUT_PULLUP, HIGH);
  metronome.New(1000);
  attachInterrupt(digitalPinToInterrupt(tiltSwitch.Pin()), tilt, CHANGE);
  Serial.begin(115200);
}

void loop() {

  if(metronome.Tick()){
    
    Serial.print("Value:");    
    Serial.print(tiltSwitch.Value());
    Serial.print("\t State:");
    Serial.println(tiltSwitch.State());
  }

  if(tilted){
    Serial.println("tilt Switch has tilted!");
    tilted = 0;
  }
}

void tilt(){
  tilted = 1;   
}

