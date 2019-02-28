#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"

Adafruit_PCD8544 display = Adafruit_PCD8544(9, 8, 7, 5, 6);

void setup()
{
    display.begin(); // Ini8ialize the display
    display.setContrast(58); // Set the contrast

    // Start device display with ID of sensor
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0,0); display.print("MPU9250");
    display.setTextSize(1);
    display.setCursor(0, 20); display.print("9-DOF 16-bit");
    display.setCursor(0, 30); display.print("motion sensor");
    display.setCursor(20,40); display.print("60 ug LSB");
    display.display();
    delay(1000);
}
void loop()
{

}
