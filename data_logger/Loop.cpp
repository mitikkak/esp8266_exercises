#include <SPI.h>
#include <SD.h>

void loop()
{
  // make a string for assembling the data to log:
  String dataString = "";
  dataString += "Hello world";

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
    if (!SD.mkdir("LOGS/"))
    {
      Serial.println("mkdir failed");
      return;
    }
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}
