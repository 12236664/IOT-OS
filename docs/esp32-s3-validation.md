# Q-SHIELD ESP32-S3 validation

## Build

```bash
idf.py set-target esp32s3
idf.py reconfigure
idf.py build
```

## Hardware validation

Use a real ESP32-S3 board and verify:

1. Secure Boot v2 signing and boot rejection of an unsigned image.
2. Flash encryption in development mode before release mode.
3. A/B OTA update, power-loss interruption, rollback, and health confirmation.
4. Wi-Fi initialization and recovery.
5. NimBLE initialization after selecting the Bluetooth controller ownership model.
6. Secure-element provisioning and signing with the chosen I2C device.
7. ML-KEM/ML-DSA provider integration on the selected ESP-IDF toolchain.

## Important

The 8 MB partition layout is a default for an 8 MB board, not a universal ESP32-S3 setting. Confirm flash size before flashing. Do not permanently burn security eFuses until the signed-image, recovery, and provisioning procedures have passed review.
