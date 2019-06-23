#include "Arduino.h"
#include "PCD8544.h"

static PCD8544 lcd=PCD8544(14,13,27,26,15);

void setup()
{
    lcd.begin(84, 48);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Connecting... ");
}

void loop()
{

}
