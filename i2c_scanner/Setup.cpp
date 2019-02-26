#include "Arduino.h"
#include "Wire.h"

void setup()
{
    Wire.begin();

    Serial.begin(115200);
    //while (!Serial);             // Leonardo: wait for serial monitor
    Serial.println("\nI2C Scanner");
}
