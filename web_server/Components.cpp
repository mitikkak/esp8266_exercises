
#include "Components.h"

static const int server_port = 80;
WiFiServer server(server_port);
LiquidCrystal_I2C lcd(0x27,16,4);
http_parser* hParser{nullptr};
http_parser_settings httpSettings{};

