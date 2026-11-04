#pragma once

#include <stdbool.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    bool wifi_ready;
    bool ble_ready;
    bool authenticated;
} qshield_radio_status_t;

esp_err_t qshield_radio_init(void);
esp_err_t qshield_radio_get_status(qshield_radio_status_t *status);
esp_err_t qshield_radio_recover(void);

#ifdef __cplusplus
}
#endif
