
int x = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  x++; 
  Serial.println(x);
  delay(500);
}

