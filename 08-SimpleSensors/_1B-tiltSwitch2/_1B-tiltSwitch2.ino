
#include "SimpleLibrary.h"

TimingManager timing;
DigitalSensor tiltSwitch;

volatile unsigned long lastTilt = millis();
volatile unsigned long thresh = 400;
volatile unsigned long tiltCount = 0;

void setup() {

  tiltSwitch.New(3, INPUT_PULLUP, HIGH);
  timing.New(200);
  attachInterrupt(digitalPinToInterrupt(tiltSwitch.Pin()), tilt, CHANGE);
  Serial.begin(9600);
}

void loop() {

  if(timing.Tick()){
    
    Serial.print("Value:");    
    Serial.print(tiltSwitch.Value());
    
    Serial.print("\t State:");
    Serial.print(tiltSwitch.State());

    Serial.print("\t Tilt Count:");
    Serial.println(tiltCount);    
  }
}

void tilt(){
  if (millis() - lastTilt > thresh){
    Serial.println("tilt Switch has tilted!");
    lastTilt = millis();
    tiltCount++;
  }
}

