#include "qshield_secure_element.h"

#include <string.h>

static qshield_secure_element_status_t g_status;

esp_err_t qshield_secure_element_init(void)
{
    /* Hardware provisioning is intentionally explicit; no software key fallback. */
    memset(&g_status, 0, sizeof(g_status));
    return ESP_ERR_NOT_SUPPORTED;
}

esp_err_t qshield_secure_element_get_status(qshield_secure_element_status_t *status)
{
    if (status == NULL) {
        return ESP_ERR_INVALID_ARG;
    }
    *status = g_status;
    return ESP_OK;
}

esp_err_t qshield_secure_element_sign(const uint8_t *message, size_t message_len,
                                      uint8_t *signature, size_t *signature_len)
{
    (void)message;
    (void)message_len;
    (void)signature;
    (void)signature_len;
    return ESP_ERR_NOT_SUPPORTED;
}
