#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    bool present;
    bool identity_ready;
    bool secure_key_storage;
} qshield_secure_element_status_t;

esp_err_t qshield_secure_element_init(void);
esp_err_t qshield_secure_element_get_status(qshield_secure_element_status_t *status);
esp_err_t qshield_secure_element_sign(const uint8_t *message, size_t message_len,
                                      uint8_t *signature, size_t *signature_len);

#ifdef __cplusplus
}
#endif
