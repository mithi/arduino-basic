
#include "SimpleLibrary.h"

Sweeper sweeper; 
Buzzer buzzer;

void setup() {
  
  sweeper.Format(0, 180, 1, NORMAL); 
  buzzer.Format(13, 1.3, 1000);
}

void loop() {
  
  alarm(2000, 1000);
}

void alarm(int startFrequency, int amplitude){
  
  const float coeff= 3.1412 / 180; // degrees -> radians 
  float sineValue = sin(coeff*sweeper.Next(1));
  int toneValue = startFrequency + int(sineValue*amplitude);
 
  buzzer.Play(toneValue, 4, 2);
}

/*
 * Try the following startFrequency and amplitude Combo
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
 *  Try
 *  buzzer.Play(toneValue, 4, 3);
 *  buzzer.Play(toneValue, 2, 1);
 *  buzzer.Play(f, soundPeriod = 3, Pause = 1); in milliseconds
 */

