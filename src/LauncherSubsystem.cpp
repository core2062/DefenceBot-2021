#include "LauncherSubsystem.h"

using namespace CORE;

LauncherSubsystem::LauncherSubsystem() : m_launcherMotor(BOTTOM_LAUNCHER_MOTOR_PORT) {
}

void LauncherSubsystem::robotInit() {
    operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER);
}

void LauncherSubsystem::teleopInit() {
}

void LauncherSubsystem::teleop() {
    m_launcherOn = false;

    if (!m_launcherOn && operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER)) {
        m_launcherOn = true;
    } else if (m_launcherOn && operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER)) {
        m_launcherOn = false;
    }

    launcherOn(m_launcherOn);

    SmartDashboard::PutNumber("Motor Percent Speed", 0.38);
}

void LauncherSubsystem::launcherOn(bool m_launcherOn) {
    if (m_launcherOn) {
        m_launcherMotor.Set(ControlMode::PercentOutput, 0.38);
    } else {
        m_launcherMotor.Set(ControlMode::PercentOutput, 0.0);
    }

}
