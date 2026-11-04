# MVP-1 build matrix

## ESP-IDF targets

Run each target from a clean working tree. The exact board must match the selected chip and flash layout.

```bash
for target in esp32 esp32s2 esp32s3 esp32c3 esp32c6; do
  idf.py set-target "$target"
  idf.py reconfigure
  idf.py build
  rm -rf build sdkconfig sdkconfig.old
 done
```

Some targets may not support every Q-SHIELD capability. Wi-Fi, Bluetooth/BLE, Secure Boot, flash encryption, and hardware acceleration must be reported from the target's ESP-IDF configuration rather than assumed by the common interface.

## Arduino Uno R3

Install the AVR core and compile the example:

```bash
arduino-cli core update-index
arduino-cli core install arduino:avr
arduino-cli compile \
  --fqbn arduino:avr:uno \
  --libraries platforms/arduino-uno-r3/src \
  platforms/arduino-uno-r3/examples/basic
```

## Acceptance criteria

- No missing headers or symbols.
- No target-specific feature is enabled on an incompatible ESP32 chip.
- Uno reports watchdog and external-transport capability accurately.
- Security-sensitive unsupported operations return an explicit error.
- Hardware flashing and secure-boot/eFuse operations remain manual release steps.

## Current limitation

The connected development environment cannot execute ESP-IDF, Arduino CLI, or physical-board tests. Build results must be collected from CI or a local development machine before declaring MVP-1 complete.
