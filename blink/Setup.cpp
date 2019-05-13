#include "Arduino.h"
#include "Led.h"

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}
