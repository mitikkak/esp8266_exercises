#include "Components.h"

static const int RX{7};
static const int TX{6};
SoftwareSerial gpsSerial(RX, TX);
TinyGPS gps;