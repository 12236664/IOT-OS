#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn default_input_continues() {
        assert_eq!(
            qshield_policy_decide(PolicyInput::default()),
            RecoveryAction::Continue
        );
    }

    #[test]
    fn hardware_fault_has_priority_over_network_signals() {
        assert_eq!(
            qshield_policy_decide(PolicyInput {
                packet_loss_percent: 100,
                authentication_failures: 10,
                hardware_fault: true,
            }),
            RecoveryAction::SafeMode
        );
    }

    #[test]
    fn thresholds_are_inclusive() {
        assert_eq!(
            qshield_policy_decide(PolicyInput {
                packet_loss_percent: 40,
                ..PolicyInput::default()
            }),
            RecoveryAction::ChangeRoute
        );
        assert_eq!(
            qshield_policy_decide(PolicyInput {
                authentication_failures: 3,
                ..PolicyInput::default()
            }),
            RecoveryAction::Quarantine
        );
    }
}
