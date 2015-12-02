
#include "SimpleLibrary.h"

TimingManager timing;
DigitalSensor tiltSwitch;

void setup() {

  tiltSwitch.New(3, INPUT_PULLUP, HIGH);
  timing.New(1000);
  attachInterrupt(digitalPinToInterrupt(tiltSwitch.Pin()), tilt, CHANGE);
  Serial.begin(9600);
}

void loop() {

  if(timing.Tick()){
    
    Serial.print("Value:");    
    Serial.print(tiltSwitch.Value());
    Serial.print("\t State:");
    Serial.println(tiltSwitch.State());
  }
}

void tilt(){
  
  Serial.println("tilt Switch has tilted!");
}

