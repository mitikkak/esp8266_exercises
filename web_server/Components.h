
#pragma once
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "http_parser.h"

extern WiFiServer server;
extern LiquidCrystal_I2C lcd;
extern http_parser* hParser;
extern http_parser_settings httpSettings;
