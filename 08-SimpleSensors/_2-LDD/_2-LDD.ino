
#include "SimpleLibrary.h"

AnalogSensor LDD; 
TimingManager LDDTiming;

void setup() {
  
  LDD.New(A5, INPUT_PULLUP, 700, HIGH, 1, 0); 
  LDDTiming.New(1000);
  Serial.begin(9600);
}

void loop() {
  
  if(LDDTiming.Tick()){
        
    Serial.print("Raw Value:");
    Serial.print(LDD.RawValue());
    
    Serial.print("\t Processed Value:");
    Serial.print(LDD.ProcessedValue());
    
    Serial.print("\t Mapped Value:");
    Serial.print(LDD.MappedRawValue(0, 512));
    
    Serial.print("\t Is True:");
    Serial.println(LDD.IsTrue());
  }
}
