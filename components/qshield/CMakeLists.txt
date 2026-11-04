# ESP32-S3 target
set(IDF_TARGET esp32s3)

idf_component_register(
    SRCS
        "qshield.c"
        "qshield_secure_element.c"
        "qshield_radio.c"
        "qshield_pqc.c"
        "qshield_ota.c"
    INCLUDE_DIRS "include"
    REQUIRES app_update bootloader_support esp_http_client esp_https_ota esp_wifi bt nvs_flash
)
