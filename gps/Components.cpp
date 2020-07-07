#include "Components.h"

#ifdef ARDUINO_ESP8266_GENERIC
Adafruit_PCD8544 lcd = Adafruit_PCD8544(0, 4, 5); // TODO: check these!
#elif defined ARDUINO_ESP8266_NODEMCU
Adafruit_PCD8544 lcd = Adafruit_PCD8544(D3, D2, D1);
#else
const uint8_t CLK = 25;
const uint8_t DIN = 26;
const uint8_t DC = 27;
const uint8_t CE = 14;
const uint8_t RESET = 12;
Adafruit_PCD8544 lcd = Adafruit_PCD8544(CLK, DIN, DC, CE, RESET);
#endif
TinyGPSPlus gps;
