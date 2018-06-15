
#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
extern LiquidCrystal_I2C lcd;

unsigned long counter = 0;
void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print(counter);
  counter++;
  lcd.setCursor(0,2);
  const unsigned long mils = millis();
  const unsigned long mils2 = millis();
  lcd.print(mils);
  lcd.print(" ");
  lcd.print(mils2);
  delay(1000);
  Serial.println("Hello");
}

