# Q-SHIELD RTOS

A security-first ESP32 IoT platform foundation integrating resilient wireless networking, post-quantum cryptography interfaces, policy-controlled recovery, and hardware health monitoring.

> **Status: Development release candidate; not production-ready.** Source-level interfaces and scaffolds are present, but target builds, hardware validation, secure provisioning, signed OTA, and cryptographic-provider integration remain release gates.

## Platform versions

- **ESP32 family:** ESP-IDF/FreeRTOS foundation. Select the exact chip with `idf.py set-target`.
- **Arduino Uno R3:** constrained watchdog and supervisory runtime. Wi-Fi, BLE, OTA, Secure Boot, flash encryption, and PQC require external hardware or remain unavailable.

## Build

```bash
idf.py set-target esp32
idf.py reconfigure
idf.py build
```

```bash
arduino-cli compile \
  --fqbn arduino:avr:uno \
  --libraries platforms/arduino-uno-r3/src \
  platforms/arduino-uno-r3/examples/basic
```

## Security boundary

PQC and secure-element operations fail closed until reviewed providers and hardware drivers are integrated. Features marked **Future patch** remain disabled or return an explicit unsupported/error result. Do not enable Secure Boot or flash-encryption eFuses on a production board until the exact board, image-signing process, recovery path, and provisioning record have been reviewed.

## Documentation

- `docs/feature-status.md` — functional, partial, and future-patch status.
- `docs/final-stage-gates.md` — final release gates.
- `docs/release-candidate-status.md` — release decision and excluded scope.
- `docs/hardware-validation-template.md` — required hardware evidence format.
- `docs/mvp1-build-matrix.md` — build targets and acceptance criteria.

Licensed under the MIT License; see `LICENSE`.
