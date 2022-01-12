#include <Servo.h>
Servo myServo;
int potpin = A0;
int val;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  val = analogRead(potpin);
  val = map(val, 0, 1024, 0, 180);
  Serial.println(val);
  myServo.write(val);
  delay(15);
}
