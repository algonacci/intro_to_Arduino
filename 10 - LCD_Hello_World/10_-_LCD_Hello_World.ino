#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Hello Anita!");
  lcd.setCursor(0, 1);
  lcd.print("Kamu Cantik Deh!");
}

void loop() {
  
}
