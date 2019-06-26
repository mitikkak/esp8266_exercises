#pragma once

#ifdef ESP8266
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
extern LiquidCrystal_I2C lcd;
#else
#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"
extern Adafruit_PCD8544 lcd;
#endif

void lcdDbg(const char* const msg);
void initLcd();

