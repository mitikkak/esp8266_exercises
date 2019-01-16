#include "Arduino.h"
#include "Pins.h"
#include "Credentials.h"
#include "Components.h"

int my_url_callback(http_parser*, const char *at, size_t length)
{
	return 0;
}
int my_header_field_callback(http_parser*, const char *at, size_t length)
{
	return 0;
}

void setup()
{
	httpSettings.on_url = my_url_callback;
	httpSettings.on_header_field = my_header_field_callback;
	hParser = static_cast<http_parser*>(malloc(sizeof(http_parser)));
	http_parser_init(hParser, HTTP_REQUEST);
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
