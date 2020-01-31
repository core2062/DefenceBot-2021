#include <LauncherSubsystem.h>
#include <Robot.h>
#include <frc/WPILib.h>

using namespace CORE;

LauncherSubsystem::LauncherSubsystem() : m_topMotor(TOP_LAUNCHER_MOTOR_PORT),
                                         m_bottomMotor(BOTTOM_LAUNCHER_MOTOR_PORT) {
}

void LauncherSubsystem::robotInit() {
    // Registers joystick axis and buttons, does inital setup for talons
    // speed adustment code start #1
    operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::A_BUTTON);
    operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::B_BUTTON);
    operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::X_BUTTON);
    operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::Y_BUTTON);
    // speed adustment code end #1
    operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER);
}

void LauncherSubsystem::teleopInit() {
    m_topMotorSpeed = 0.50;
    m_bottomMotorSpeed = 0.50;
}

void LauncherSubsystem::teleop() {
    bool launcherOn = false;
    // speed adustment code start #2
    bool m_yButtonPressed = operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::Y_BUTTON);
    bool m_aButtonPressed = operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::A_BUTTON);
    bool m_xButtonPressed = operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::X_BUTTON);
    bool m_bButtonPressed = operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::B_BUTTON);
    // speed adustment code end #2

    if (!launcherOn && operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER)) {
        launcherOn = true;
    } else if (launcherOn && operatorJoystick->GetRisingEdge(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER)) {
        launcherOn = false;
    }

    // speed adustment code start #3
    // Changes motor speeds
    if (m_yButtonPressed && m_topMotorSpeed < 1) {
        // Increases top motor speed by 1 percent
        m_topMotorSpeed = m_topMotorSpeed + 0.05;
    } else if (m_aButtonPressed && (m_topMotorSpeed > -1)) {
        // Decreases top motor speed by 1 percent
        m_topMotorSpeed = m_topMotorSpeed - 0.05;
    } else if (m_xButtonPressed && (m_bottomMotorSpeed < 1)) {
        // Increases top motor speed by 1 percent
        m_bottomMotorSpeed = m_bottomMotorSpeed + 0.05;
    } else if (m_bButtonPressed && (m_bottomMotorSpeed > -1)) {
        // Decreases top motor speed by 1 percent
        m_bottomMotorSpeed = m_bottomMotorSpeed - 0.05;
    }
    // speed adustment code end #3

    if (launcherOn) {
        m_topMotor.Set(ControlMode::PercentOutput, m_topMotorSpeed);
        m_bottomMotor.Set(ControlMode::PercentOutput, m_bottomMotorSpeed);
    } else {
        m_topMotor.Set(ControlMode::PercentOutput, 0.0);
        m_bottomMotor.Set(ControlMode::PercentOutput, 0.0);
    }

    SmartDashboard::PutNumber("Top Motor Percent Speed", m_topMotorSpeed);
    SmartDashboard::PutNumber("Bottom Motor Percent Speed", m_bottomMotorSpeed);
}
