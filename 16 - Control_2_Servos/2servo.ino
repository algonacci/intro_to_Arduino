#include <Servo.h>

Servo servo1;
Servo servo2;
String data_serial_receive;

int pos1 = 90;
int pos2 = 90;

void setup() {
  Serial.begin(74880);
  servo1.attach(9);
  servo2.attach(5);
}

void loop() {
  if (Serial.available() > 0) {
    data_serial_receive = Serial.readStringUntil('\n');
    
    if(data_serial_receive == "1") {
      pos1 = 180;
      pos2 = 0;
      servo1.write(pos1);
      servo2.write(pos2);
      delay(5000);
      servo1.write(90);
      servo2.write(90);
      }

     if(data_serial_receive == "0") {
      pos1 = 0;
      pos2 = 180;
      servo1.write(pos1);
      servo2.write(pos2);
      delay(5000);
      servo1.write(90);
      servo2.write(90);
     }
  }
}
