#include "ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() : 
        m_climber(CLIMBER_UP_PORT, CLIMBER_DOWN_PORT) {
}

void ClimberSubsystem::robotInit() {
    operatorJoystick->RegisterButton(CORE::COREJoystick::LEFT_BUTTON);
}

void ClimberSubsystem::teleopInit() {
    m_climberExtended = false;
}

void ClimberSubsystem::teleop() {
    if (!m_climberExtended && operatorJoystick->GetRisingEdge(CORE::COREJoystick::LEFT_BUTTON)) {
        m_climberExtended = true;
    } else if (m_climberExtended && operatorJoystick->GetRisingEdge(CORE::COREJoystick::LEFT_BUTTON)) {
        m_climberExtended = false;
    }

    climberMove(m_climberExtended);

}

void ClimberSubsystem::climberMove(bool m_climberExtended) {
    if (m_climberExtended) {
        m_climber.Set(DoubleSolenoid::kForward);
    } else if (!m_climberExtended) {
        m_climber.Set(DoubleSolenoid::kReverse);
    }
}
