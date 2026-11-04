#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn hardware_fault_enters_safe_mode() {
        let action = qshield_policy_decide(PolicyInput {
            hardware_fault: true,
            ..PolicyInput::default()
        });
        assert_eq!(action, RecoveryAction::SafeMode);
    }

    #[test]
    fn repeated_authentication_failures_quarantine() {
        let action = qshield_policy_decide(PolicyInput {
            authentication_failures: 3,
            ..PolicyInput::default()
        });
        assert_eq!(action, RecoveryAction::Quarantine);
    }

    #[test]
    fn high_packet_loss_changes_route() {
        let action = qshield_policy_decide(PolicyInput {
            packet_loss_percent: 40,
            ..PolicyInput::default()
        });
        assert_eq!(action, RecoveryAction::ChangeRoute);
    }
}
