#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    bool enable_wifi;
    bool enable_ble;
    bool enable_fault_monitor;
    bool require_secure_boot;
} qshield_config_t;

typedef struct {
    int32_t temperature_milli_c;
    uint32_t supply_millivolts;
    uint32_t reset_count;
    bool radio_healthy;
} qshield_health_sample_t;

qshield_config_t qshield_default_config(void);
esp_err_t qshield_init(const qshield_config_t *config);
esp_err_t qshield_health_sample(qshield_health_sample_t *sample);

#ifdef __cplusplus
}
#endif
