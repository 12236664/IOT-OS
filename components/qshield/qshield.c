#include "qshield.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_timer.h"

static const char *TAG = "qshield-core";
static qshield_config_t g_config;
static bool g_initialized;

qshield_config_t qshield_default_config(void)
{
    return (qshield_config_t){
        .enable_wifi = true,
        .enable_ble = true,
        .enable_fault_monitor = true,
        .require_secure_boot = true,
    };
}

esp_err_t qshield_init(const qshield_config_t *config)
{
    if (config == NULL) {
        return ESP_ERR_INVALID_ARG;
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
    if (!g_initialized || sample == NULL) {
        return ESP_ERR_INVALID_STATE;
    }

    /* Hardware-specific sensors and radio probes are intentionally isolated here. */
    sample->temperature_milli_c = 0;
    sample->supply_millivolts = 0;
    sample->reset_count = esp_reset_reason();
    sample->radio_healthy = g_config.enable_wifi || g_config.enable_ble;
    return ESP_OK;
}
