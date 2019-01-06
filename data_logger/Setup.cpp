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

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

static const int chipSelect = 2;

LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void lcdDbg(const char* const msg)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(msg);
    delay(1000);
}

void setup()
{
  lcd.init();                      // initialize the lcd
  lcd.backlight();

  lcdDbg("Initializing SD card");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
      lcdDbg("Card failed, or not present");
    // don't do anything more:
    return;
  }
  lcdDbg("card initialized.");
}









