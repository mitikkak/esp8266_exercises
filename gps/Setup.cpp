#include "Arduino.h"
#include "Components.h"

void setup()
{
  lcd.begin();
  lcd.setContrast(50);
  Serial.begin(9600);
}
