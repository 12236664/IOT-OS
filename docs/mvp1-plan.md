# MVP-1 implementation plan

## Current stage

MVP-1 focuses on buildability, capability reporting, and hardware bring-up. It does not claim production cryptography, secure provisioning, OTA security, mesh recovery, or cognitive-radio support.

## Development order

1. Build the Arduino Uno R3 example and every selected ESP-IDF target.
2. Add target capability detection so Wi-Fi, BLE, secure boot, and flash encryption are not assumed.
3. Replace placeholder ESP32 health values with supported board measurements or explicit unknown values.
4. Add authenticated external transport framing for the Uno-to-ESP32 path.
5. Integrate one selected secure element on one representative ESP32 board.
6. Integrate one reviewed cryptographic provider and run known-answer tests.
7. Harden OTA only after signed-image and rollback tests exist.

## Future patches

The following remain intentionally deferred: full BLE/NimBLE behavior, secure-element production provisioning, ML-KEM/ML-DSA provider integration, signed OTA manifests, downgrade protection, self-healing mesh, cognitive radio, and tamper-evident audit storage.

Each deferred item must be moved out of the Future patch list only after implementation, tests, and hardware evidence are available.
