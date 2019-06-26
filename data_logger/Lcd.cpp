
#include "Lcd.h"
#include "Arduino.h"

#ifdef ESP8266
LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#else
const uint8_t H_SCK = 14;
const uint8_t H_MOSI = 13;
const uint8_t DC = 27;
const uint8_t H_SS = 15;
const uint8_t RESET = 26;
Adafruit_PCD8544 lcd = Adafruit_PCD8544(H_SCK, H_MOSI, DC, H_SS, RESET);
#endif

void initLcd()
{
#ifdef ESP8266
  lcd.init();                      // initialize the lcd
  lcd.backlight();
#else
  lcd.begin();
  lcd.setContrast(40);
#endif
}

void lcdDbg(const char* const msg)
{
#ifdef ESP8266
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(msg);
#else
    lcd.clearDisplay();
    lcd.setCursor(0,0);
    for (int i = 0; i < strlen(msg); i++) // TODO: move to Adafruit_PCD8544
    {
        lcd.write(msg[i]);
    }
#endif
    Serial.println(msg);
    delay(1000);
}

