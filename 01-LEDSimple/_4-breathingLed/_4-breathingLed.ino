
int pin = 9;
int maxBrightness = 150;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  SweepUp(pin, 5, 30);
  SweepDown(pin, 5, 30);
  delay(500);
}

void SweepUp(int pin, int fadeAmount, int waitTime){
  for(int brightness = 0; brightness <= maxBrightness; brightness+=fadeAmount)
    setLed(p, brightness, waitTime);  
}

void SweepDown(int pin, int fadeAmount, int waitTime){
  for(int brightness = maxBrightness; brightness >= 0; brightness-=fadeAmount)
    setLed(p, brightness, waitTime);
}

void setLed(int p, int b, int d){
  analogWrite(p, b);
  delay(d);
}

/**
 * Try SweepUp() only
 * Try SweepDown() only
 * Mess with maxBrightness, waitTime, fadeAmount - what happens?
 * 
 */
