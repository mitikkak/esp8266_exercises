#include "Arduino.h"

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ArduinoOTA.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>
#include <WebSocketsServer.h>

#define LED_RED     15            // specify the pins with an RGB LED connected
#define LED_GREEN   12
#define LED_BLUE    13

static const char *ssid = "ESP8266 Access Point"; // The name of the Wi-Fi network that will be created
static const char *password = "thereisnospoon";   // The password required to connect to it, leave blank for an open network

static const char *OTAName = "ESP8266";           // A name and a password for the OTA service
static const char *OTAPassword = "esp8266";

static const char* mdnsName = "esp8266"; // Domain name for the mDNS responder

extern ESP8266WebServer server;
extern ESP8266WiFiMulti wifiMulti;
extern WebSocketsServer webSocket;
extern File fsUploadFile;
extern bool rainbow;

String formatBytes(size_t bytes);
