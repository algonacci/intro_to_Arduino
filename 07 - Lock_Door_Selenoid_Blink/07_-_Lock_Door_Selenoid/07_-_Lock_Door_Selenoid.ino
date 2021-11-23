int blinking_pin = 13;

void setup() {
  pinMode(blinking_pin, OUTPUT);
}

void loop() {
  digitalWrite(blinking_pin, LOW);
  delay(1000);
  digitalWrite(blinking_pin, HIGH);
  delay(1000);
}
