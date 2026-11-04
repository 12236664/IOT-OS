#include "qshield_uno.h"

#include <Arduino.h>
#include <avr/wdt.h>

namespace qshield {

void begin() {
  Serial.begin(115200);
  wdt_enable(WDTO_2S);
}

Health sample_health() {
  Health health{};
  health.uptime_ms = millis();
  health.watchdog_enabled = 1;
  return health;
}

void service() {
  wdt_reset();
}

}  // namespace qshield
