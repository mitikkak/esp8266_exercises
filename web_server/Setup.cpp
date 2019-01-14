#include "Arduino.h"
#include "Pins.h"
#include "Credentials.h"
#include "Components.h"

void setup()
{
    lcd.init();
    // Connect to Wi-Fi network with SSID and password
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Connecting to ");
    lcd.setCursor(0,1);
    lcd.print(ssid);
    lcd.setCursor(0,2);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        lcd.print(".");
    }
    // Print local IP address and start web server
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("IP address: ");
    lcd.setCursor(0,1);
    lcd.print(WiFi.localIP());
    server.begin();
}
