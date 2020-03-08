#include "ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() : 
        m_climberSolnoidOne(2, CLIMBER_UP_PORT_ONE, CLIMBER_DOWN_PORT_ONE),
        m_climberSolnoidTwo(2, CLIMBER_UP_PORT_TWO, CLIMBER_DOWN_PORT_TWO) {
}

void ClimberSubsystem::robotInit() {
    driverJoystick->RegisterButton(CORE::COREJoystick::Y_BUTTON);
}

void ClimberSubsystem::teleopInit() {
    m_climberExtended = false;
}

void ClimberSubsystem::teleop() {
    if (!m_climberExtended && driverJoystick->GetRisingEdge(CORE::COREJoystick::Y_BUTTON)) {
        m_climberExtended = true;
        climberMove(m_climberExtended);
    } else if (m_climberExtended && driverJoystick->GetRisingEdge(CORE::COREJoystick::Y_BUTTON)) {
        m_climberExtended = false;
        climberMove(m_climberExtended);
    }


}

void ClimberSubsystem::climberMove(bool m_climberExtended) {
    if (m_climberExtended) {
        m_climberSolnoidOne.Set(DoubleSolenoid::kForward);
        m_climberSolnoidTwo.Set(DoubleSolenoid::kForward);
    } else if (!m_climberExtended) {
        m_climberSolnoidOne.Set(DoubleSolenoid::kReverse);
        m_climberSolnoidTwo.Set(DoubleSolenoid::kReverse);
    }
}
