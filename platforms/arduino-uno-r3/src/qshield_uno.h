#pragma once

#include <stdint.h>

namespace qshield {

struct Health {
  uint32_t uptime_ms;
  uint8_t watchdog_enabled;
  uint8_t transport_available;
};

void begin();
Health sample_health();
void service();

}  // namespace qshield
