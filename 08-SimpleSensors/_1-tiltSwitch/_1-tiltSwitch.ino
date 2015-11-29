
#include "SimpleLibrary.h"

TimingManager printTiming;
DigitalSensor tiltSwitch;

void setup() {

  tiltSwitch.New(3, INPUT_PULLUP, HIGH);
  printTiming.New(1000);
  attachInterrupt(digitalPinToInterrupt(tiltSwitch.Pin()), tilt, CHANGE);
  Serial.begin(9600);
}

void loop() {

  if(printTiming.IsTimeToUpdate()){
    
    Serial.println("TILT SWITCH!");
    Serial.print("Value:");
    
    Serial.println(tiltSwitch.Value());
    Serial.print("State:");
    
    Serial.println(tiltSwitch.State());
    Serial.println(" ");
  }
}

void tilt(){
  
  Serial.println("tilt Switch has tilted!");
}

