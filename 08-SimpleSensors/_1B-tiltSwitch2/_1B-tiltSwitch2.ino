
#include "SimpleLibrary.h"

Metronome metronome;
DigitalSensor tiltSwitch;

volatile unsigned long lastTilt = millis();
volatile unsigned long thresh = 400;
volatile unsigned long tiltCount = 0;
volatile bool tilted = 0;

void setup() {

  tiltSwitch.Format(3, INPUT_PULLUP, HIGH);
  metronome.Format(200);
  attachInterrupt(digitalPinToInterrupt(tiltSwitch.Pin()), tilt, CHANGE);
  Serial.begin(115200);
}

void loop() {

  if(metronome.Tick()){
    
    Serial.print("Value:");    
    Serial.print(tiltSwitch.Value());
    
    Serial.print("\t State:");
    Serial.print(tiltSwitch.State());

    Serial.print("\t Tilt Count:");
    Serial.println(tiltCount);    
  }

  if(tilted){
    
    Serial.println("tilt Switch has tilted!");
    tilted = 0;  
  }
}

void tilt(){
  unsigned long mil = millis();
  
  if (mil - lastTilt > thresh){
    
    lastTilt = mil;
    tiltCount++;
    tilted = 1;
  }
}

