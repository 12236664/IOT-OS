# Q-SHIELD security and provisioning

## Secure boot and flash encryption

The ESP-IDF project enables Secure Boot v2, release-mode flash encryption, OTA rollback, and anti-rollback defaults through `sdkconfig.defaults`. These options are hardware- and lifecycle-sensitive: test on the exact ESP32 variant and provision production keys through a controlled manufacturing process. Never commit private keys or plaintext provisioning material.

Recommended production sequence:

1. Select and document the exact ESP32 variant and eFuse plan.
2. Build and test signed images on development hardware.
3. Verify rollback and recovery with power-loss tests.
4. Provision device-unique keys using a secure manufacturing station.
5. Permanently enable eFuses only after an approved production review.

## Secure element seam

`qshield_secure_element.h` defines the narrow interface required for device identity and protected key operations. A production implementation should target a reviewed secure element such as an ATECC608-family device or an ESP hardware-backed identity path, with I2C bus protection and manufacturing provisioning controls.

## PQC seam

`qshield_pqc.h` exposes ML-KEM and ML-DSA adapter boundaries. The repository intentionally does not embed an unreviewed cryptographic implementation. Integrate a maintained, reviewed library compatible with the product license, memory budget, timing requirements, and selected ESP32 toolchain. Use hybrid classical/PQC sessions during migration.

## OTA recovery

The OTA component uses ESP-IDF partition selection and image verification hooks. Production integration must configure an A/B partition table, signed images, rollback confirmation after health checks, anti-rollback policy, resumable downloads, and power-loss testing.
