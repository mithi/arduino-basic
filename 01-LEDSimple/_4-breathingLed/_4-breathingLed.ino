
const int ledPin = 11;
const int maxBrightness = 150;
const int delta = 1;
const int msDelay = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  SweepUp(ledPin);
  SweepDown(ledPin);
  delay(400);
}

void SweepUp(int pin) {
  for(int brightness = 0; brightness <= maxBrightness; brightness+=delta)
    setLed(pin, brightness, msDelay);
}

void SweepDown(int pin) {
  for(int brightness = maxBrightness; brightness >= 0; brightness-=delta)
    setLed(pin, brightness, msDelay);
}

void setLed(int p, int b, int d) {
  analogWrite(p, b);
  delay(d);
}

/**
 * Try SweepUp() only
 * Try SweepDown() only
 * Mess with maxBrightness, waitTime, fadeAmount - what happens? 
 */
