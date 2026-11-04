#include <Arduino.h>
#include "qshield_uno.h"

void setup() {
  qshield::begin();
}

void loop() {
  qshield::service();
  const qshield::Health health = qshield::sample_health();
  Serial.print(F("uptime_ms="));
  Serial.print(health.uptime_ms);
  Serial.print(F(" watchdog="));
  Serial.print(health.watchdog_enabled);
  Serial.print(F(" external_transport="));
  Serial.println(health.transport_available);
  delay(1000);
}
