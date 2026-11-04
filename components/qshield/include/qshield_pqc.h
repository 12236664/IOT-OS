#pragma once

#include <stddef.h>
#include <stdint.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Link a reviewed provider before enabling production cryptographic use. */
esp_err_t qshield_pqc_init(void);
esp_err_t qshield_mlkem_encapsulate(const uint8_t *peer_key, size_t peer_key_len,
                                     uint8_t *ciphertext, size_t *ciphertext_len,
                                     uint8_t *shared_secret, size_t *shared_secret_len);
esp_err_t qshield_mldsa_verify(const uint8_t *message, size_t message_len,
                               const uint8_t *signature, size_t signature_len,
                               const uint8_t *public_key, size_t public_key_len);

#ifdef __cplusplus
}
#endif
