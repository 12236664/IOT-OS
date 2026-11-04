#!/usr/bin/env bash
set -Eeuo pipefail

# Run from the repository root with ESP-IDF exported.
for target in esp32 esp32s2 esp32s3 esp32c3 esp32c6; do
  echo "=== Building $target ==="
  idf.py set-target "$target"
  idf.py reconfigure
  idf.py build
  rm -rf build sdkconfig sdkconfig.old
 done

# Arduino CLI must be installed separately.
arduino-cli compile \
  --fqbn arduino:avr:uno \
  --libraries platforms/arduino-uno-r3/src \
  platforms/arduino-uno-r3/examples/basic
