
const int ledPin = 11;
int onTime = 1000;
int offTime = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  ledBlink(ledPin, 1000, 500);
}

void ledBlink(int pin, int onTime, int offTime){
  digitalWrite(pin, HIGH);
  delay(onTime);
  digitalWrite(pin, LOW);
  delay(offTime);
}

