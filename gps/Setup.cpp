#include "Arduino.h"
#include "Components.h"

#ifdef ESP8266
    #ifdef ARDUINO_ESP8266_GENERIC
    static const int chipSelect = 0; // TODO!! Set proper pin value!
    #else
    static const int chipSelect = D4;
    #endif
#else
static const int chipSelect = 5;
#endif

void setup()
{
  lcd.begin();
  lcd.setContrast(50);
  lcd.setCursor(0,0);
  Serial.begin(9600);
#ifdef ESP8266
  if (!SD.begin(chipSelect))
#else
  if (!SD.begin())
#endif
  {
      lcd.clearDisplay();
      lcd.print("Card failed, or not present");
      lcd.display();
      delay(5000);
    // don't do anything more:
    return;
  }
}
