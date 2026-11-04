# Q-SHIELD RTOS

A security-first ESP32 IoT platform foundation integrating resilient wireless networking, post-quantum cryptography interfaces, cognitive-radio policy hooks, and hardware health monitoring.

> **Status:** Early foundation / research prototype. Cryptographic and radio implementations are intentionally represented by explicit interfaces until they are reviewed and integrated with production-ready libraries and certified hardware.

## Target

- Hardware: ESP32 family
- Radio: Wi-Fi + Bluetooth/BLE, with an extensible radio abstraction
- Languages: C/C++ with ESP-IDF and Rust for security/policy components
- Runtime: ESP-IDF FreeRTOS foundation

## Repository layout

```text
main/                         ESP-IDF application entry point
components/qshield/           C interfaces and health-monitoring scaffold
rust/qshield-policy/          Rust policy engine scaffold
docs/                         Architecture and threat-model notes
tests/                        Host-side characterization tests
```

## Build the ESP-IDF scaffold

```bash
idf.py set-target esp32
idf.py build
idf.py flash monitor
```

The current scaffold does not claim production post-quantum security. Integrate a reviewed PQC implementation, secure element, secure boot, flash encryption, and signed OTA policy before deployment.

## Development principles

1. Keep the trusted computing base small.
2. Isolate radio, security, update, and health services.
3. Fail closed for identity and firmware verification failures.
4. Make recovery actions policy-controlled and auditable.
5. Add tests before replacing interfaces with hardware-specific implementations.

Licensed under the MIT License; see `LICENSE`.
