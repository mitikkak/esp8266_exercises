
#ifdef ARDUINO_ESP8266_GENERIC
// ESP8266-07 in my lab actually...
static constexpr int ledPin{2};
#else
static constexpr int ledPin{LED_BUILTIN};
#endif
