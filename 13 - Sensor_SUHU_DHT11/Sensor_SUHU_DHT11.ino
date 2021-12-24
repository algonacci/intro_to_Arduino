#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // GANTI 0x3F Ke 0x27 kalau LCD ga muncul
#include <DHT.h>
DHT dht(2, DHT11); //Pin, Jenis DHT

int powerPin = 3;    // untuk pengganti VCC/5vOLT
 
void setup(){
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight(); 
  // jadikan pin power sebagai output
  pinMode(powerPin, OUTPUT);
  // default bernilai LOW
  digitalWrite(powerPin, LOW);
 Serial.begin(9600);
 dht.begin();
}
 
void loop(){
 digitalWrite(powerPin, HIGH);
  
 float kelembaban = dht.readHumidity();
 float suhu = dht.readTemperature();

 Serial.print("kelembaban: ");
 Serial.print(kelembaban);
 Serial.print(" ");
 Serial.print("suhu: ");
 Serial.println(suhu);
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Kelembaban: ");
  lcd.setCursor(11,0);
  lcd.print(kelembaban);

  lcd.setCursor(0,1);
  lcd.print("Suhu: ");
  lcd.setCursor(5,1);
  lcd.print(suhu);
  delay(1000);
}
