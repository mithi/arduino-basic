
const int ledPin = 11;
const int maxBrightness = 150;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  SweepUp(ledPin, 5, 30);
  SweepDown(ledPin, 5, 30);
  delay(500);
}

void SweepUp(int pin, int fadeAmount, int waitTime){
  for(int brightness = 0; brightness <= maxBrightness; brightness+=fadeAmount)
    setLed(pin, brightness, waitTime);  
}

void SweepDown(int pin, int fadeAmount, int waitTime){
  for(int brightness = maxBrightness; brightness >= 0; brightness-=fadeAmount)
    setLed(pin, brightness, waitTime);
}

void setLed(int p, int b, int d){
  analogWrite(p, b);
  delay(d);
}

/**
 * Try SweepUp() only
 * Try SweepDown() only
 * Mess with maxBrightness, waitTime, fadeAmount - what happens? 
 */
 
