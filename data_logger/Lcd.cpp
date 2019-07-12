
#include "Lcd.h"
#include "Arduino.h"

#ifdef ESP8266
Adafruit_PCD8544 lcd = Adafruit_PCD8544(D3, D2, D1);
#else
const uint8_t CLK = 25;
const uint8_t DIN = 26;
const uint8_t DC = 27;
const uint8_t CE = 14;
const uint8_t RESET = 12;
Adafruit_PCD8544 lcd = Adafruit_PCD8544(CLK, DIN, DC, CE, RESET);
#endif

void initLcd()
{
  lcd.begin();
  lcd.setContrast(50);
}

void lcdDbg(const char* const msg)
{
    lcd.clearDisplay();
    lcd.setCursor(0,0);
    for (int i = 0; i < strlen(msg); i++) // TODO: move to Adafruit_PCD8544
    {
        lcd.write(msg[i]);
    }
    lcd.display();
    Serial.println(msg);
    delay(1000);
}

