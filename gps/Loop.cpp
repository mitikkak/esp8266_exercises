
#include "Arduino.h"
#include "Components.h"

bool readGps()
{
    bool ret{false};
    while (Serial.available())
    {
        ret = true;
        gps.encode(Serial.read());
    }
    return ret;
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
const char* const separator = "|";
void row(const int r)
{
    static const int textSize{2};
    lcd.setCursor(0, r*8*textSize);
}

unsigned long prevTimeDisplayed{0};
bool timeToDisplay()
{
    return (millis() - prevTimeDisplayed) > 1000;
}
void loop()
{
  bool const gpsUpdated = readGps();
  if (timeToDisplay() and gpsUpdated)
  {
      prevTimeDisplayed = millis();
      lcd.clearDisplay();
      row(0);
//      lcd.print("GSA: ");
      lcd.print(gps.gsa.amount());
      lcd.print(separator);
      lcd.print(gps.gsa.numSats());
      lcd.print(separator);
//      lcd.print(gps.gsa.mode());
//      lcd.print(separator);
      lcd.print(gps.gsa.fix());
      row(1);
//      lcd.print("GSV: ");
      lcd.print(gps.satsInView.messageAmount());
      lcd.print(separator);
      const int numSats = gps.satsInView.numOf();
      lcd.print(numSats);
#if 0
      lcd.print("->");
      for (int i = 0; i < numSats; i++)
      {
          const auto& sat = gps.satsInView[i];
          lcd.print(sat.id());
          lcd.print(separator);
      }
#endif
      lcd.display();
  }
#if 0
  lcd.print(" SATS: ");
  lcd.print(gps.satellites());
  String message("Sats: ");
  message += gps.satellites();
  writeToSd(message);
#endif
  lcd.display();
}
