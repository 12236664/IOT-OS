#pragma once

#include <stdbool.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    bool pending_verify;
    bool rollback_available;
} qshield_ota_status_t;

esp_err_t qshield_ota_init(void);
esp_err_t qshield_ota_start(const char *url);
esp_err_t qshield_ota_confirm_running_image(void);
esp_err_t qshield_ota_get_status(qshield_ota_status_t *status);

#ifdef __cplusplus
}
#endif
