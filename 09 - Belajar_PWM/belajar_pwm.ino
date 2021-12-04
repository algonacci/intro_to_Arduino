#define in1 2
#define in2 3
#define ENA 5
#define sensor A0

int data_sensor; // 0 - 1023
int data_pwm = 0; // 0 - 255

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {

  data_sensor = analogRead(sensor);

//  data_pwm = map(data_sensor, 0, 1023, 0, 255);

  if (data_sensor > 511) {
    data_pwm = 255;
  }
  else {
     data_pwm = 0;
  }
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ENA, data_pwm);
  
}

void maju() {
  
}
