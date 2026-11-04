#include <Arduino.h>
#include "qshield_uno.h"

void setup() {
  qshield::begin();
}

void loop() {
  qshield::service();
  const qshield::Health health = qshield::sample_health();
  Serial.println(health.uptime_ms);
  delay(1000);
}
