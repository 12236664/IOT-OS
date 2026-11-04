#include "qshield_pqc.h"

#include "esp_err.h"

esp_err_t qshield_pqc_init(void)
{
    /* Refuse to operate until a reviewed PQC provider is linked. */
    return ESP_ERR_NOT_SUPPORTED;
}

esp_err_t qshield_mlkem_encapsulate(const uint8_t *peer_key, size_t peer_key_len,
                                     uint8_t *ciphertext, size_t *ciphertext_len,
                                     uint8_t *shared_secret, size_t *shared_secret_len)
{
    (void)peer_key;
    (void)peer_key_len;
    (void)ciphertext;
    (void)ciphertext_len;
    (void)shared_secret;
    (void)shared_secret_len;
    return ESP_ERR_NOT_SUPPORTED;
}

esp_err_t qshield_mldsa_verify(const uint8_t *message, size_t message_len,
                               const uint8_t *signature, size_t signature_len,
                               const uint8_t *public_key, size_t public_key_len)
{
    (void)message;
    (void)message_len;
    (void)signature;
    (void)signature_len;
    (void)public_key;
    (void)public_key_len;
    return ESP_ERR_NOT_SUPPORTED;
}
