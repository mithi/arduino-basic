
#include "SimpleLibrary.h"

AnalogSensor LDD; 
Metronome metronome;

void setup() {
  
  LDD.Format(A5, INPUT_PULLUP, 700, HIGH, 1, 0); 
  metronome.Format(1000);
  Serial.begin(115200);
}

void loop() {
  
  if(metronome.Tick()){
        
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
