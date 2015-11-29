
#include "SimpleLibrary.h"

AnalogSensor LDD; 
TimingManager LDDTiming;

void setup() {
  
  LDD.New(A5, INPUT_PULLUP, 500, HIGH, 1, 0); 
  LDDTiming.New(1000);
  Serial.begin(9600);
}

void loop() {
  
  if(LDDTiming.IsTimeToUpdate()){
    
    Serial.println("Light Dependent Diode!");
    
    Serial.print("Raw Value:");
    Serial.println(LDD.RawValue());
    
    Serial.print("Processed Value:");
    Serial.println(LDD.ProcessedValue());
    
    Serial.print("Mapped Value:");
    Serial.println(LDD.MappedRawValue(0, 512));
    
    Serial.print("Is True:");
    Serial.println(LDD.IsTrue());
    
    Serial.println(" ");
  }
}
