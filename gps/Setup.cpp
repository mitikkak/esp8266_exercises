#include "Arduino.h"
#include "Components.h"

void setup()
{
  lcd.init();                      // initialize the lcd
  Serial.begin(9600);
}
