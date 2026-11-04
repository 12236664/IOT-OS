#![no_std]

/// Recovery actions exposed to the C/ESP-IDF integration seam.
#[repr(u8)]
#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub enum RecoveryAction {
    Continue = 0,
    ChangeRoute = 1,
    ChangeChannel = 2,
    Quarantine = 3,
    SafeMode = 4,
}

/// Minimal, deterministic policy input. Validation and signature verification
/// belong at the boundary before this function is called.
#[repr(C)]
#[derive(Clone, Copy, Debug, Default)]
pub struct PolicyInput {
    pub packet_loss_percent: u8,
    pub authentication_failures: u8,
    pub hardware_fault: bool,
}

#[no_mangle]
pub extern "C" fn qshield_policy_decide(input: PolicyInput) -> RecoveryAction {
    if input.hardware_fault {
        RecoveryAction::SafeMode
    } else if input.authentication_failures >= 3 {
        RecoveryAction::Quarantine
    } else if input.packet_loss_percent >= 40 {
        RecoveryAction::ChangeRoute
    } else {
        RecoveryAction::Continue
    }
}

#[cfg(test)]
mod tests;
