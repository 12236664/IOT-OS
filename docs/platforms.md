# Q-SHIELD platform variants

This repository now keeps separate platform versions behind common service interfaces.

## ESP32 family

Path: `platforms/esp32/`

Use ESP-IDF and select the exact chip at build time:

```bash
idf.py set-target esp32       # Original ESP32
idf.py set-target esp32s2     # ESP32-S2
idf.py set-target esp32s3     # ESP32-S3
idf.py set-target esp32c3     # ESP32-C3
idf.py set-target esp32c6     # ESP32-C6
idf.py build
```

Secure Boot, flash encryption, OTA, Wi-Fi, BLE, and partition settings must be validated per chip and board. Not every ESP32 family supports every radio or security feature.

## Arduino Uno R3

Path: `platforms/arduino-uno-r3/`

Use the Arduino IDE or Arduino CLI. The Uno R3 version is a constrained companion runtime for the ATmega328P. It provides watchdog supervision, health reporting, serial command framing, and policy hooks. It does not claim native Wi-Fi, BLE, ESP-IDF, Secure Boot, ESP flash encryption, OTA, or practical ML-KEM/ML-DSA support.

Those capabilities must be delegated to an external ESP32/radio module or secure element.

## Common interface rule

Platform adapters may implement only the capabilities available on the board. Unsupported security-sensitive operations must return an explicit failure rather than silently falling back to an insecure implementation.
