
#include "Arduino.h"
#include "Components.h"

void readGps()
{
  while (Serial.available())
  {
      gps.encode(Serial.read());
  }
}
void writeToSd(String const message)
{
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    if (!SD.mkdir("/nl"))
    {
        lcd.print("mkdir failed");
        return;
    }
    const char* filename = "/nl/datalog.txt";
#if defined ESP8266
    File dataFile = SD.open(filename, FILE_WRITE);
#else if defined ESP32
    File dataFile = SD.open(filename, FILE_APPEND);
#endif

    // if the file is available, write to it:
    if (dataFile)
    {
        dataFile.println(message);
    }
    // if the file isn't open, pop up an error:
    else
    {
        lcd.print("error opening file");
    }
    dataFile.close();
}
void loop()
{
  readGps();
  lcd.clearDisplay();
  lcd.setCursor(0,0);
  lcd.print("HDOP: ");
  lcd.print(gps.hdop());
  lcd.print(" SATS: ");
  lcd.print(gps.satellites());
  lcd.display();
  String message("Sats: ");
  message += gps.satellites();
  writeToSd(message);
}
