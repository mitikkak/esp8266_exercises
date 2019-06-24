
#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Pins.h"
extern LiquidCrystal_I2C lcd;

volatile byte button1Counter = 0;
volatile byte button2Counter = 0;
volatile byte button3Counter = 0;
volatile byte button4Counter = 0;
int numberOfInterrupts = 0;

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  const unsigned long mils = millis();
  lcd.print(mils);
  lcd.setCursor(0,1);
  lcd.print("B1: "); lcd.print(button1Counter);
  lcd.print(" B2: "); lcd.print(button2Counter);
  if (button1Counter)
  {
      digitalWrite(led1, HIGH);
      button1Counter = 0;
  }
  if (button2Counter)
  {
      digitalWrite(led1, LOW);
      button2Counter = 0;
  }
  delay(1000);
}

