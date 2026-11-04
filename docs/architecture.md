# Q-SHIELD RTOS foundation architecture

## Scope

This repository starts with an ESP-IDF/FreeRTOS integration seam. It is not yet a complete operating system or a production cryptographic implementation.

## Service boundaries

- **Core/kernel seam:** ESP-IDF and FreeRTOS provide scheduling, interrupts, memory, and drivers.
- **Security service:** owns identity, secure boot status, key lifecycle, attestation, and PQC adapters.
- **Radio service:** presents one interface over Wi-Fi and BLE and later LoRa/802.15.4 adapters.
- **Recovery service:** manages health states, route recovery, quarantine, and signed A/B updates.
- **Health service:** collects hardware and link diagnostics and emits authenticated events.
- **Rust policy service:** evaluates signed, versioned policies without owning hardware drivers.

## Security boundaries

No service should directly access another service's private keys or persistent state. Production work must add ESP32 secure boot, flash encryption, hardware-backed identity, authenticated storage, and reviewed ML-KEM/ML-DSA libraries.

## Initial state machine

`NORMAL -> DEFENSIVE -> QUARANTINE` for security events, and `NORMAL -> RECOVERY -> SAFE` for hardware or firmware failures. Every transition must be logged and bounded by policy.
