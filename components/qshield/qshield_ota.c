#include "qshield_ota.h"

#include <string.h>
#include "esp_https_ota.h"
#include "esp_ota_ops.h"

static qshield_ota_status_t g_status;

esp_err_t qshield_ota_init(void)
{
    const esp_partition_t *running = esp_ota_get_running_partition();
    const esp_partition_t *configured = esp_ota_get_boot_partition();
    g_status.pending_verify = running != NULL && configured != NULL && running != configured;
    g_status.rollback_available = esp_ota_get_last_invalid_partition() != NULL;
    return ESP_OK;
}

esp_err_t qshield_ota_start(const char *url)
{
    if (url == NULL || url[0] == '\0') {
        return ESP_ERR_INVALID_ARG;
    }

    esp_http_client_config_t http_config = {
        .url = url,
        .keep_alive_enable = true,
    };
    esp_https_ota_config_t ota_config = {
        .http_config = &http_config,
    };
    esp_err_t err = esp_https_ota(&ota_config);
    if (err == ESP_OK) {
        g_status.pending_verify = true;
    }
    return err;
}

esp_err_t qshield_ota_confirm_running_image(void)
{
    const esp_partition_t *running = esp_ota_get_running_partition();
    if (running == NULL) {
        return ESP_ERR_INVALID_STATE;
    }
    return esp_ota_mark_app_valid_cancel_rollback();
}

esp_err_t qshield_ota_get_status(qshield_ota_status_t *status)
{
    if (status == NULL) {
        return ESP_ERR_INVALID_ARG;
    }
    *status = g_status;
    return ESP_OK;
}
