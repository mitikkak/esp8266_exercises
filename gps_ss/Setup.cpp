#include "Components.h"

void setup()
{
    gpsSerial.begin(9600);
    Serial.begin(115200);
}