
#include "SimpleLibrary.h"

Sweeper sweeper; 
Buzzer buzzer;

void setup() {
  
  sweeper.New(0, 180, NORMAL); 
  buzzer.New(13, 1.3, 1000);
}

void loop() {
  
  alarm(2000, 1000);
}

void alarm(int startFrequency, int amplitude){
  
  const float coeff= 3.1412 / 180; // to convert degrees to radians 
  float sineValue = sin(coeff*sweeper.Update(1));
  int toneValue = startFrequency + int(sineValue*amplitude);
 
  buzzer.Pitch(toneValue);
}

/*
 * Try the following startFrequency and Amplitude Combo
 * 1000 1000 
 * 2000 1000
 * 3000 1000
 * 1000 500
 * 1000 1500
 * 1000 2500
 * 2000 500
 * 2000 1500
 * 2000 2500
 * 
 */

