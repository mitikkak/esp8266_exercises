
#include "Arduino.h"

static const int ledPin = 2;
void loop()
{
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    //_SERIAL.println("HIGH");
    delay(1000);                       // wait for a second
    digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
    //_SERIAL.println("LOW");
    delay(1000);                       // wait for a second
}
