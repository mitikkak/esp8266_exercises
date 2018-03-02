
#include "Arduino.h"

static const int ledPin = 2;
void loop()
{
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(14, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(16, HIGH);   // turn the LED on (HIGH is the voltage level)
    //_SERIAL.println("HIGH");
    delay(1000);                       // wait for a second
    digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(14, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(16, LOW);    // turn the LED off by making the voltage LOW
    //_SERIAL.println("LOW");
    delay(1000);                       // wait for a second
}
