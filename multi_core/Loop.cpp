
#include "Arduino.h"
#include "Led.h"

void loop()
{
    Serial.println("HIGH");
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    Serial.println("LOW");
    digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
}
