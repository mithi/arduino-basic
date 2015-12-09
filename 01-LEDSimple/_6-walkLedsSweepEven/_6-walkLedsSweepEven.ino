
const int MAX_BRIGHTNESS = 200;
const int DELAY = 500;

const int pin[6] = {11, 10, 9, 6, 5, 3};

const int DELTA = 1;
const int SWEEP_DELAY = 5;

void setup() {
  initializePins();  
}

void loop() {
  walkLEDs();
}

void walkLEDs() {
  for (int x = 0; x < 6; x++) {
    offLeds();
    x % 2 == 0 ? blinkLed(x) : Sweep(x);
  }
}

void initializePins() {
  for (int x = 0; x < 6; x ++)
    pinMode(pin[x], OUTPUT);
}

void offLeds() {
  for (int x = 0; x < 6; x ++)
    setLed(x, 0, 0);
}

void blinkLed(int x) {
  setLed(x, MAX_BRIGHTNESS, DELAY);
  setLed(x, 0, DELAY);
}

void Sweep(int x) {
  SweepUp(x);
  SweepDown(x);
}

void SweepUp(int x) {
  for (int brightness = 0; brightness <= MAX_BRIGHTNESS; brightness+=DELTA)
    setLed(x, brightness, SWEEP_DELAY);
}

void SweepDown(int x) {
  for (int brightness = MAX_BRIGHTNESS; brightness >= 0; brightness-=DELTA)
    setLed(x, brightness, SWEEP_DELAY);
}

void setLed(int p, int b, int d) {
  analogWrite(pin[p], b);
  delay(d);
}
