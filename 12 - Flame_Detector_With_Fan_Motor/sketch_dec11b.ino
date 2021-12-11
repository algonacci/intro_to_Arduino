// Flame Sensor Module

int LED = 13; // Use the onboard Uno LED
int isFlamePin = 7;  // This is our input pin
int isFlame = HIGH;  // HIGH MEANS NO FLAME
int inA = 9;         //inisialisasi pin INA di fan motor
int inB = 8;         //inisialisasi pin INB di fan motor

void setup() {
  pinMode(LED, OUTPUT); // put onboard LED as output
  pinMode(isFlamePin, INPUT); //flame sensor should be input as it is giving data
  pinMode (inA, OUTPUT);           //menetapkan pin 9 sebagai output
  pinMode (inB, OUTPUT);           //menetapkan pin 8 sebagai output
  Serial.begin(9600); //begin Serial communication
  
}

void loop() {
  isFlame = digitalRead(isFlamePin);//Readd the data gien by the flame sensor
  if (isFlame== LOW)  //if it is low
  {
    Serial.println("FLAME, FLAME, FLAME"); //Print Flame Flame
    digitalWrite(LED, HIGH);  //LED on
    digitalWrite (inA, LOW);
    digitalWrite (inB, HIGH);
  }
  else                           //if not
  {                               
    Serial.println("no flame"); //print no  flame
    digitalWrite(LED, LOW);    //off the LED
    digitalWrite (inA, LOW);
    digitalWrite (inB, LOW);
  }
}
