
#include "SimpleLibrary.h"

AnalogSensor TemperatureSensor; 
TimingManager timing;

void setup() {
  
  TemperatureSensor.New(A5, INPUT, 500, LOW, 5/10.24, -1); 
  timing.New(1000);
  
  Serial.begin(9600);
}

void loop() {
  
  if(timing.Tick()){
    
    Serial.print("Processed Value:");
    Serial.print(TemperatureSensor.ProcessedValue());

    Serial.print("\t Raw Value:");
    Serial.print(TemperatureSensor.RawValue());
    
    Serial.print("\t Mapped Value:");
    Serial.print(TemperatureSensor.MappedRawValue(0, 512));
  
    Serial.print("\t Is True:");
    Serial.println(TemperatureSensor.IsTrue());    
  }
}


