#include "qshield.h"
#include "qshield_radio.h"

#include "esp_log.h"
#include "esp_system.h"

static const char *TAG = "qshield-core";
static qshield_config_t g_config;
static bool g_initialized;
static qshield_radio_status_t g_radio_status;

qshield_config_t qshield_default_config(void)
{
    return (qshield_config_t){
        .enable_wifi = true,
        /* BLE remains disabled until the target-specific NimBLE adapter is linked. */
        .enable_ble = false,
        .enable_fault_monitor = true,
        .require_secure_boot = true,
    };
}

esp_err_t qshield_init(const qshield_config_t *config)
{
    if (config == NULL) return ESP_ERR_INVALID_ARG;
    if (config->enable_ble) return ESP_ERR_NOT_SUPPORTED;

    if (config->enable_wifi) {
        esp_err_t err = qshield_radio_init();
        if (err != ESP_OK) return err;
        err = qshield_radio_get_status(&g_radio_status);
        if (err != ESP_OK || !g_radio_status.wifi_ready) {
            return err == ESP_OK ? ESP_ERR_INVALID_STATE : err;
        }
    } else {
        g_radio_status = (qshield_radio_status_t){0};
    }

    g_config = *config;
    g_initialized = true;
    ESP_LOGI(TAG, "security=%s wifi=%s ble=%s fault-monitor=%s",
             g_config.require_secure_boot ? "required" : "optional",
             g_config.enable_wifi ? "on" : "off",
             g_config.enable_ble ? "on" : "off",
             g_config.enable_fault_monitor ? "on" : "off");
    return ESP_OK;
}

esp_err_t qshield_health_sample(qshield_health_sample_t *sample)
{
    if (!g_initialized || sample == NULL) return ESP_ERR_INVALID_STATE;

    sample->temperature_milli_c = 0;
    sample->supply_millivolts = 0;
    sample->reset_count = (uint32_t)esp_reset_reason();
    sample->radio_healthy = g_config.enable_wifi && g_radio_status.wifi_ready;
    return ESP_OK;
}
