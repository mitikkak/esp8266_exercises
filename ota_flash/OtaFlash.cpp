#include "Arduino.h"
#ifdef ESP8266
#include <ESP8266WiFi.h>
//#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#else
#include "WiFi.h"
#endif
#include <ArduinoOTA.h>

const char *ssid = "ESPap";
const char *password = "thereisnospoon";

const int ESP_BUILTIN_LED = LED_BUILTIN;

void setup()
{
    Serial.begin(115200);
    Serial.println("Booting");
    WiFi.softAP(ssid, password);

    // Port defaults to 8266
    // ArduinoOTA.setPort(8266);

    // Hostname defaults to esp8266-[ChipID]
    ArduinoOTA.setHostname("myesp8266");

    // No authentication by default
    // ArduinoOTA.setPassword((const char *)"123");

    ArduinoOTA.onStart([]() {
      Serial.println("Start");
    });
    ArduinoOTA.onEnd([]() {
      Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });
    ArduinoOTA.begin();
    Serial.println("Ready");
    Serial.print("IP address: ");
    Serial.println(WiFi.softAPIP());
    pinMode(ESP_BUILTIN_LED, OUTPUT);
}

unsigned int ledState = LOW;
unsigned long timeLedChanged = 0;

void loop()
{
    ArduinoOTA.handle();
    if (millis() - timeLedChanged > 1000)
    {
        ledState = (ledState == HIGH) ? LOW : HIGH;
        digitalWrite(ESP_BUILTIN_LED, ledState);
        timeLedChanged = millis();
    }
}
