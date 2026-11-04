#include "qshield_uno.h"

#include <Arduino.h>
#include <avr/wdt.h>

namespace qshield {

void begin() {
  MCUSR = 0;
  wdt_disable();
  Serial.begin(115200);
  wdt_enable(WDTO_2S);
}

Health sample_health() {
  Health health{};
  health.uptime_ms = millis();
  health.watchdog_enabled = 1;
  // Uno R3 has no native network radio; an external transport is required.
  health.transport_available = 0;
  return health;
}

void service() {
  wdt_reset();
}

}  // namespace qshield
