
#include "Arduino.h"
#include <SD.h>

bool beginSdCard()
{
    Serial.println("Begin SD card...");
#ifdef ESP32
    if (!SD.begin())
#else
    static const int chipSelect = D4;
    if (!SD.begin(chipSelect))
#endif
    {
        Serial.println("Card failed, or not present");
        return false;
    }
    return true;
}
const char* const typeNameNone{"None"};
const char* const typeNameMissing{"Missing"};
const char* const typeNameMmc{"Mmc"};
const char* const typeNameSd{"Sd"};
const char* const typeNameSd2{"Sd2"};
const char* const typeNameSdHc{"SdHc"};
const char* const typeNameUnknown{"Unknown"};
#ifdef ESP32
void printCardType()
{
    sdcard_type_t const t = SD.cardType();
    const char* typeName =
                      (t == CARD_MMC) ? typeNameMmc :
                      (t == CARD_SD) ? typeNameSd:
                      (t == CARD_SDHC) ? typeNameSdHc :
                      (t == CARD_NONE) ? typeNameNone :
                                         typeNameUnknown;
    Serial.printf("Card type[%d] %s \n\r", t, typeName);
}
#else
void printCardType()
{
    uint8_t const t = SD.type();
    const char* typeName =
                      (t == SD_CARD_TYPE_SD1) ? typeNameSd :
                      (t == SD_CARD_TYPE_SD2) ? typeNameSd2:
                      (t == SD_CARD_TYPE_SDHC) ? typeNameSdHc :
                      typeNameUnknown;
    Serial.printf("Card type[%d] %s \n\r", t, typeName);
}
#endif
void printCardSize()
{
#ifdef ESP32
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %llu MB\n\r", cardSize);
#else
    size_t cardSize = SD.size() / (1024 * 1024);
    Serial.printf("SD Card Size: %u MB\n\r", cardSize);
#endif
}

#ifdef ESP32
void listDir(fs::FS &fs, const char * dirname, uint8_t levels){
#else
    void listDir(SDClass &fs, const char * dirname, uint8_t levels){
#endif
    Serial.printf("Listing directory: %s\n\r", dirname);

    File root = fs.open(dirname);
    if(!root){
        Serial.println("Failed to open directory");
        return;
    }
    if(!root.isDirectory()){
        Serial.println("Not a directory");
        return;
    }

    File file = root.openNextFile();
    while(file){
        if(file.isDirectory()){
            Serial.print("  DIR : ");
            Serial.println(file.name());
            if(levels){
                listDir(fs, file.name(), levels -1);
            }
        } else {
            Serial.print("  FILE: ");
            Serial.print(file.name());
            Serial.print("  SIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
}
void printCardContent()
{
    listDir(SD, "/", 0);
}
String rootpath = "/";
int DeletedCount = 0;
int FolderDeleteCount = 0;
int FailCount = 0;

void rm(File dir, String tempPath)
{

  while(true) {
    File entry =  dir.openNextFile();

    Serial.println();
    if (entry) {

      Serial.printf("(1) %s\n\r", entry.name());
      if ( entry.isDirectory() )
      {
        rm(entry, entry.name());

        if( SD.rmdir( entry.name() ) )
        {
          Serial.print("Deleted folder ");
          Serial.printf("(2) %s\n\r", entry.name());
          FolderDeleteCount++;
        }
        else
        {
          Serial.print("Unable to delete folder ");
          Serial.printf("(3) %s\n\r", entry.name());
          FailCount++;
        }
      }
      else
      {
        if( SD.remove( entry.name() ) )
        {
          Serial.print("Deleted ");
          Serial.printf("(4) %s\n\r", entry.name());
          DeletedCount++;
        }
        else
        {
          Serial.print("Failed to delete ");
          Serial.printf("(5) %s\n\r", entry.name());
          Serial.printf("exists: %u \n\r", SD.exists(entry.name()));
          FailCount++;
        }

      }
    }
    else {
      // break out of recursion
      break;
    }
  }
}
void deleteAllFiles()
{
  File dir = SD.open("/");
  rm(dir, rootpath);
}
void waitToProceed()
{
    Serial.println("Press space to proceed");
    while (' ' != Serial.read())
    {
        delay(100);
    }
}
void setup()
{
    Serial.begin(115200);
    waitToProceed();
    if (!beginSdCard())
    {
        return;
    }
    printCardType();
    waitToProceed();
    printCardSize();
    waitToProceed();
    if (SD.exists("/DATALOG6.TXT"))
    {
        Serial.println("exists");
    }
    else
    {
        Serial.println(" not exists");
        beginSdCard();
    }
}
void loop()
{
    printCardContent();
    waitToProceed();
    Serial.println("Will delete all files...");
    waitToProceed();
    deleteAllFiles();
    Serial.printf("Stats: [%d][%d][%d] \n\r", DeletedCount, FolderDeleteCount, FailCount);
}
