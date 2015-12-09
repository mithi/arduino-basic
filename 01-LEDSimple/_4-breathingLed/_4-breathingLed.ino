
const int ledPin = 11;
const int MAX_BRIGHTNESS = 150;
const int DELTA = 1;
const int SWEEP_DELAY = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  SweepUp(ledPin);
  SweepDown(ledPin);
  delay(400);
}

void SweepUp(int pin) {
  for(int brightness = 0; brightness <= MAX_BRIGHTNESS; brightness+=DELTA)
    setLed(pin, brightness, SWEEP_DELAY);
}

void SweepDown(int pin) {
  for(int brightness = MAX_BRIGHTNESS; brightness >= 0; brightness-=DELTA)
    setLed(pin, brightness, SWEEP_DELAY);
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
