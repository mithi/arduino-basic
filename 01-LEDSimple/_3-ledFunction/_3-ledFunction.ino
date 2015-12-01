
const int ledPin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  ledUpdate(ledPin, 1000, HIGH);
  ledUpdate(ledPin, 500, LOW);  
}

void ledUpdate(int pin, int waitTime, bool value){
  digitalWrite(pin, value);
  delay(waitTime);
}

