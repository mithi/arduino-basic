
#include "SimpleLibrary.h"

AnalogSensor TemperatureSensor; 
TimingManager TemperatureSensorTiming;

void setup() {
  
  TemperatureSensor.New(A5, INPUT, 500, LOW, 5/10.24, -1); 
  TemperatureSensorTiming.New(1000);
  
  Serial.begin(9600);
}

void loop() {
  
  if(TemperatureSensorTiming.IsTimeToUpdate()){
  
    Serial.println("Temperature Sensor!");
  
    Serial.print("Raw Value:");
    Serial.println(TemperatureSensor.RawValue());
  
    Serial.print("Processed Value:");
    Serial.println(TemperatureSensor.ProcessedValue());
  
    Serial.print("Mapped Value:");
    Serial.println(TemperatureSensor.MappedRawValue(0, 512));
  
    Serial.print("Is True:");
    Serial.println(TemperatureSensor.IsTrue());
    
    Serial.println(" ");
  }
}


