#include "qshield_radio_v2.h"

#include "esp_event.h"
#include "esp_netif.h"
#include "esp_wifi.h"

static qshield_radio_status_t g_status;

esp_err_t qshield_radio_init(void)
{
    esp_err_t err = esp_netif_init();
    if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        return err;
    }

    err = esp_event_loop_create_default();
    if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        return err;
    }

    wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT();
    err = esp_wifi_init(&wifi_config);
    if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        return err;
    }

    g_status.wifi_ready = true;
    /* BLE/NimBLE startup is kept behind its own adapter to avoid sharing
       controller ownership with applications that configure Bluetooth later. */
    g_status.ble_ready = false;
    g_status.authenticated = false;
    return ESP_OK;
}

esp_err_t qshield_radio_get_status(qshield_radio_status_t *status)
{
    if (status == NULL) {
        return ESP_ERR_INVALID_ARG;
    }
    *status = g_status;
    return ESP_OK;
}

esp_err_t qshield_radio_recover(void)
{
    if (!g_status.wifi_ready) {
        return qshield_radio_init();
    }
    return esp_wifi_stop();
}
