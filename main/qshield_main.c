#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "qshield.h"

static const char *TAG = "qshield";

void app_main(void)
{
    qshield_config_t config = qshield_default_config();
    esp_err_t err = qshield_init(&config);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Q-SHIELD initialization failed: %s", esp_err_to_name(err));
        return;
    }

    ESP_LOGI(TAG, "Q-SHIELD RTOS foundation started");
    while (true) {
        qshield_health_sample_t sample;
        if (qshield_health_sample(&sample) == ESP_OK) {
            ESP_LOGI(TAG, "health: temp=%d mC voltage=%u mV", sample.temperature_milli_c,
                     sample.supply_millivolts);
        }
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
