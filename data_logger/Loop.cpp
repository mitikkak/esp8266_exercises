#include <SPI.h>
#include <SD.h>

int counter = 0;

extern void lcdDbg(const char* const msg);

void loop()
{
    // make a string for assembling the data to log:
    String dataString = "Hello world:";
    dataString += String(counter++);

    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    if (!SD.mkdir("LOGS/"))
    {
        lcdDbg("mkdir failed");
        return;
    }
    File dataFile = SD.open("datalog.txt", FILE_WRITE);

    // if the file is available, write to it:
    if (dataFile)
    {
        dataFile.println(dataString);
        // print to the serial port too:
        lcdDbg(dataString.c_str());
        String const size_str = "filesize now: " + String(dataFile.size());
        lcdDbg(size_str.c_str());
        dataFile.close();
    }
    // if the file isn't open, pop up an error:
    else
    {
        lcdDbg("error opening datalog.txt");
    }
}
