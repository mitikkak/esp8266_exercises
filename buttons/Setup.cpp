#include "Arduino.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Pins.h"

LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void handleInterrupt1()
{
    extern volatile byte button1Counter;
    button1Counter++;
}
void handleInterrupt2()
{
    extern volatile byte button2Counter;
    button2Counter++;
}
void setup()
{
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  pinMode(button1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button1), handleInterrupt1, FALLING);
  pinMode(button2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button2), handleInterrupt2, FALLING);
  pinMode(led1, OUTPUT);
  digitalWrite(led1, HIGH);
//  Serial.begin(115200);
}
