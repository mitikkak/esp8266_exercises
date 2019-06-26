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
#include "Lcd.h"

#ifdef ESP8266
static const int chipSelect = 2;
#else
static const int chipSelect = 5;
#endif

void setup()
{
    Serial.begin(115200);
    initLcd();
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









