# Q-SHIELD functional status

This document is the source of truth for the current development stage. A feature marked **Future patch** must not be described or released as production-ready.

## Status legend

- **Functional in source:** implemented at the interface/runtime level, but still requires target build and hardware validation.
- **Partial:** some behavior exists, but the complete feature is not implemented.
- **Future patch:** intentionally deferred or currently unavailable.

## Platform status

| Feature | ESP32 family | Arduino Uno R3 | Status / next patch |
|---|---|---|---|
| Core initialization | Functional in source | Functional in source | Build and board validation required |
| Watchdog supervision | Partial | Functional in source | Add reset-cause persistence and recovery tests |
| Health reporting | Partial | Partial | Replace placeholder values with board-specific measurements |
| Wi-Fi | Partial, ESP-IDF scaffold | Future patch; external module required | Add station provisioning, events, reconnect, and capability guards |
| BLE/NimBLE | Future patch on supported ESP32 targets | Future patch; external module required | Add target-specific controller initialization and tests |
| External transport | Future patch | Partial | Add authenticated UART/SPI protocol and framing |
| Secure Boot | Configuration only | Future patch; unavailable natively | Complete per-board signing and manufacturing validation |
| Flash encryption | Configuration only | Future patch; unavailable natively | Complete per-board provisioning and recovery validation |
| OTA A/B update | Partial | Future patch; external updater required | Add signed manifest, certificate validation, downgrade protection, and power-loss tests |
| Secure element | Interface only | Future patch; external device required | Select device and implement I2C driver, provisioning, and signing tests |
| ML-KEM | Interface only | Future patch | Integrate and review a provider; add known-answer and resource tests |
| ML-DSA | Interface only | Future patch | Integrate and review a provider; add signature and resource tests |
| Policy engine | Scaffold | Future patch | Connect policy decisions to runtime actions and audit events |
| Self-healing mesh | Future patch | Future patch | Design and implement constrained recovery state machine |
| Cognitive radio | Future patch | Future patch | Add legal spectrum policy and hardware-specific sensing only |
| Tamper-evident audit log | Future patch | Future patch | Add secure storage, monotonic counters, and export format |

## Release rule

Only features marked **Functional in source** may enter build validation. Features marked **Partial** require explicit test coverage and a documented limitation. Features marked **Future patch** must remain disabled or return an explicit unsupported/error result.

## Current milestone

**MVP-1: Multi-platform Build and Hardware Bring-up**

MVP-1 is not complete until the ESP-IDF and Arduino builds pass and at least one representative board from each platform family is tested. Secure Boot, flash encryption, OTA, secure-element, and PQC claims remain unverified until hardware and provider tests pass.
