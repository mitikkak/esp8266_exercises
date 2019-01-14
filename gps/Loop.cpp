
#include "Arduino.h"
#include "Components.h"

void readGps()
{
  while (Serial.available())
  {
      gps.encode(Serial.read());
  }
}
void loop()
{
  readGps();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HDOP: ");
  lcd.print(gps.hdop());
}