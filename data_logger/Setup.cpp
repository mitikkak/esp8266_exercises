/*
  SD card datalogger

 This example shows how to log data from three analog sensors
 to an SD card using the SD library.

 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

#ifdef ESP8266
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#endif

#ifdef ESP8266
static const int chipSelect = 2;
#else
static const int chipSelect = 5;
#endif

#ifdef ESP8266
LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#endif

void lcdDbg(const char* const msg)
{
#ifdef ESP8266
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(msg);
#endif
    Serial.println(msg);
    delay(1000);
}

void setup()
{
    Serial.begin(115200);
#ifdef ESP8266
  lcd.init();                      // initialize the lcd
  lcd.backlight();
#endif
  lcdDbg("Initializing SD card");

  // see if the card is present and can be initialized:
#ifdef ESP8266
  if (!SD.begin(chipSelect))
#else
  if (!SD.begin())
#endif
  {
      lcdDbg("Card failed, or not present");
    // don't do anything more:
    return;
  }
  lcdDbg("card initialized.");
}









