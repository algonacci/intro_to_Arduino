#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 7;
const int echoPin = 6;
long duration;
int distance;


#define ledAman 8
#define led1 2
#define led2 3
#define led3 4

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledAman, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Ukur Jarak");
  lcd.setCursor(0, 1);
  lcd.print("Sederhana");
  delay(2000);
  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ada objek!");
  lcd.setCursor(0, 1);
  lcd.print("Jarak: ");
  lcd.setCursor(7, 1);
  lcd.print(distance);
  lcd.setCursor(10, 1);
  lcd.print("cm");
  delay(500);

  if (distance >= 16) 
  {
      digitalWrite(ledAman, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3,LOW);
  }
  else {
    digitalWrite(ledAman,LOW);
  }
  
  if (distance <= 15) 
  {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3,LOW);
  }
  
  if (distance < 10) {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led3,LOW);      
  } 
  
  if (distance < 5) {
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
  }
}
