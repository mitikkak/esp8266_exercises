#include "Arduino.h"
#include "Led.h"

unsigned long prevTimePrinted{0};
bool timeToPrint()
{
    return (millis() - prevTimePrinted) >= 1000;
}
void Keepalive( void * parameter) {
  for(;;)
  {
    if (timeToPrint())
    {
        Serial.printf("[%lu] Keepalive @core %u \n\r", millis(), xPortGetCoreID());
        prevTimePrinted = millis();
    }
  }
}

const uint32_t keepaliveStackSize{1000};
void * const keepaliveArgs{NULL};
UBaseType_t const keepalivePrio{2};
TaskHandle_t keepaliveHandle{};
const BaseType_t keepaliveCore{0};

bool ledOn{false};
unsigned long prevTimeLedToggled{0};
unsigned long ledPeriod{1000};
bool timeToLight()
{
    return (not ledOn) and ((millis() - prevTimeLedToggled) >= ledPeriod);
}
void LedLighter( void * parameter) {
  for(;;)
  {
    if (timeToLight())
    {
        Serial.printf("[%lu] LedLighter @core %u \n\r", millis(), xPortGetCoreID());
        digitalWrite(ledPin, HIGH);
        prevTimeLedToggled = millis();
    }
  }
}
const uint32_t ledLighterStackSize{1000};
void * const ledLighterArgs{NULL};
UBaseType_t const ledLighterPrio{2};
TaskHandle_t ledLighterHandle{};
const BaseType_t ledLighterCore{0};

bool timeToDouse()
{
    return (ledOn) and ((millis() - prevTimeLedToggled) >= ledPeriod);
}
void LedDouser( void * parameter) {
  for(;;)
  {
    if (timeToDouse())
    {
        Serial.printf("[%lu] LedDouser @core %u \n\r", millis(), xPortGetCoreID());
        digitalWrite(ledPin, LOW);
        prevTimeLedToggled = millis();
    }
  }
}

const uint32_t ledDouserStackSize{1000};
void * const ledDouserArgs{NULL};
UBaseType_t const ledDouserPrio{2};
TaskHandle_t ledDouserHandle{};
const BaseType_t ledDouserCore{0};

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  xTaskCreatePinnedToCore(&Keepalive,
                          "Keepalive",
                          keepaliveStackSize,
                          keepaliveArgs,
                          keepalivePrio,
                          &keepaliveHandle,
                          keepaliveCore);
  xTaskCreatePinnedToCore(&LedLighter,
                          "LedLighter",
                          ledLighterStackSize,
                          ledLighterArgs,
                          ledLighterPrio,
                          &ledLighterHandle,
                          ledLighterCore);
  xTaskCreatePinnedToCore(&LedDouser,
                          "LedDouser",
                          ledDouserStackSize,
                          ledDouserArgs,
                          ledDouserPrio,
                          &ledDouserHandle,
                          ledDouserCore);
}
