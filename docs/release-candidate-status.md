# Q-SHIELD release-candidate status

## Release decision

**Status: Not released / validation incomplete.**

The source foundation is suitable for continued development, but the project cannot be declared production-ready until the hardware, build, security, and recovery evidence below is attached.

## Included in this branch

- ESP-IDF FreeRTOS application foundation.
- Portable ESP32-family target selection.
- ESP32 Wi-Fi initialization and recovery scaffold.
- Arduino Uno R3 watchdog and health-runtime scaffold.
- Rust policy-engine interface and characterization tests.
- OTA partition and rollback interfaces.
- Fail-closed secure-element and PQC interfaces.
- Feature-status and future-patch tracking.

## Explicitly excluded from this release

| Feature | Reason |
|---|---|
| Production BLE/NimBLE adapter | Target-specific implementation and tests are incomplete |
| Secure-element provisioning | Device, wiring, provisioning procedure, and evidence are not fixed |
| ML-KEM/ML-DSA production provider | Reviewed provider and known-answer tests are not integrated |
| Signed OTA manifest verification | Manifest format, signing key process, and downgrade tests are incomplete |
| Arduino authenticated transport | External module and protocol interoperability are not implemented |
| Self-healing mesh | Recovery state machine and radio validation are incomplete |
| Cognitive radio | Hardware sensing and regulatory policy are not implemented |
| Tamper-evident audit log | Secure storage and monotonic-counter design are incomplete |

## Required evidence before release

- Build logs for every selected ESP32 target and Arduino Uno R3.
- Host Rust test results.
- At least one tested ESP32 board and one tested Uno R3.
- Secure Boot and flash-encryption provisioning record for each released ESP32 board.
- OTA invalid-signature, downgrade, rollback, and power-loss results.
- Threat-model review and manufacturing/recovery procedure.
- Dependency, license, and static-analysis review.

Until all required evidence is available, this branch is a development release candidate only. Future-patch items must remain disabled or return an explicit unsupported result.
