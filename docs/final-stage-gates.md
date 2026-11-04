# Q-SHIELD development status

This status is intentionally conservative. Source-level implementation is not the same as hardware-validated production readiness.

## Final-stage definition

The project reaches its final development stage only when every required feature has implementation, automated tests, target builds, hardware evidence, and release documentation.

## Current release gates

| Gate | Status | Evidence required |
|---|---|---|
| ESP32-family builds | Pending | CI or local logs for each selected target |
| Arduino Uno build | Pending | Arduino CLI compile output |
| ESP32 Wi-Fi initialization | Functional in source | Board test with connection/recovery logs |
| ESP32 BLE/NimBLE | Future patch | Target-specific adapter and tests |
| Uno external transport | Future patch | Authenticated UART/SPI protocol and interoperability test |
| Secure Boot | Configuration only | Signed-image rejection and recovery test |
| Flash encryption | Configuration only | Provisioning, encrypted flash, and recovery evidence |
| OTA rollback | Partial | Signed manifest, downgrade rejection, power-loss test |
| Secure element | Interface only | Selected device driver and provisioning evidence |
| ML-KEM/ML-DSA | Interface only | Reviewed provider, known-answer tests, resource measurements |
| Rust policy engine | Functional in source | Host test and embedded integration evidence |
| Hardware health sensing | Partial | Board-specific sensor implementation or explicit unknown state |
| Self-healing mesh | Future patch | Policy/state-machine implementation and radio tests |
| Cognitive radio | Future patch | Legal spectrum policy and validated hardware sensing |
| Audit log | Future patch | Tamper-evident storage and export tests |

## Future patch policy

Items marked **Future patch** remain disabled or return an explicit unsupported error. They must not be represented as complete in release notes, documentation, or product claims.

## Final release checklist

- [ ] All selected target builds pass.
- [ ] Host and embedded tests pass.
- [ ] Secure Boot and flash-encryption procedures are reviewed.
- [ ] OTA signing, rollback, downgrade, and power-loss tests pass.
- [ ] Secure-element provisioning is reproducible and audited.
- [ ] PQC provider is reviewed and benchmarked on each target.
- [ ] Uno transport authentication is tested with an ESP32 gateway.
- [ ] Threat model and manufacturing procedures are approved.
- [ ] Remaining Future patch items are either implemented or explicitly excluded from the release scope.
