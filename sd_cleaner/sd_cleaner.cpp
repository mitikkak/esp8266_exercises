
#include "Arduino.h"
#include <SD.h>

bool beginSdCard()
{
    Serial.println("Begin SD card...");
    if (!SD.begin())
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
const char* const typeNameSdHc{"SdHc"};
const char* const typeNameUnknown{"Unknown"};
const char* getCardTypeName(sdcard_type_t const t)
{
    const char* ret = (t == CARD_MMC) ? typeNameMmc :
                      (t == CARD_SD) ? typeNameSd:
                      (t == CARD_SDHC) ? typeNameSdHc :
                      (t == CARD_NONE) ? typeNameNone :
                                         typeNameUnknown;
    return ret;
}
void printCardType()
{
    sdcard_type_t const t = SD.cardType();
    const char* const typeName = getCardTypeName(t);
    Serial.printf("Card type[%d] %s \n\r", t, typeName);
}
void printCardSize()
{
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SD Card Size: %lluMB\n\r", cardSize);
}
void listDir(fs::FS &fs, const char * dirname, uint8_t levels){
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

      Serial.println(entry.name());
      if ( entry.isDirectory() )
      {
        rm(entry, entry.name());

        if( SD.rmdir( entry.name() ) )
        {
          Serial.print("Deleted folder ");
          Serial.println(entry.name());
          FolderDeleteCount++;
        }
        else
        {
          Serial.print("Unable to delete folder ");
          Serial.println(entry.name());
          FailCount++;
        }
      }
      else
      {
        if( SD.remove( entry.name() ) )
        {
          Serial.print("Deleted ");
          Serial.println(entry.name());
          DeletedCount++;
        }
        else
        {
          Serial.print("Failed to delete ");
          Serial.println(entry.name());
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
    while (' ' != Serial.read());
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
