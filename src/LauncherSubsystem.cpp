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
    operatorJoystick->registerButton(CORE::COREJoystick::JoystickButton::A_BUTTON);
    operatorJoystick->registerButton(CORE::COREJoystick::JoystickButton::B_BUTTON);
    operatorJoystick->registerButton(CORE::COREJoystick::JoystickButton::X_BUTTON);
    operatorJoystick->registerButton(CORE::COREJoystick::JoystickButton::Y_BUTTON);
    // speed adustment code end #1
    operatorJoystick->registerButton(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER);
}

void LauncherSubsystem::teleopInit() {
    m_topMotorSpeed = 0.50;
    m_bottomMotorSpeed = 0.50;
}

void LauncherSubsystem::teleop() {
    bool launcherOn = false;
        // speed adustment code start #2
    bool m_yButtonPressed = operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::Y_BUTTON);
    bool m_aButtonPressed = operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::A_BUTTON);
    bool m_xButtonPressed = operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::X_BUTTON);
    bool m_bButtonPressed = operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::B_BUTTON);
        // speed adustment code end #2


    if (!launcherOn && operatorJoystick->getRisingEdge(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER)) {
        launcherOn = true;
    } else if (launcherOn && operatorJoystick->getRisingEdge(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER)) {
        launcherOn = false;
    }
    
    if (launcherOn) {
        m_topMotor.Set(ControlMode::PercentOutput, m_topMotorSpeed);
        m_bottomMotor.Set(ControlMode::PercentOutput, m_bottomMotorSpeed);
    } else {
        m_topMotor.Set(ControlMode::PercentOutput, 0.0);
        m_bottomMotor.Set(ControlMode::PercentOutput, 0.0);
    }
    // speed adustment code start #3
    // Changes motor speeds
    if (m_yButtonPressed) {
        // Increases top motor speed by 2 percent
        m_topMotorSpeed = m_topMotorSpeed + 0.1;
    } else if (m_aButtonPressed) {
        // Decreases top motor speed by 2 percent
        m_topMotorSpeed = m_topMotorSpeed - 0.1;
    } else if (m_xButtonPressed) {
        // Increases top motor speed by 2 percent
        m_bottomMotorSpeed = m_bottomMotorSpeed + 0.1;
    } else if (m_bButtonPressed) {
        // Decreases top motor speed by 2 percent
        m_bottomMotorSpeed = m_bottomMotorSpeed - 0.1;
    }
    // speed adustment code end #3
    SmartDashboard::PutNumber("Top Motor Percent Speed", m_topMotorSpeed);
    SmartDashboard::PutNumber("Bottom Motor Percent Speed", m_bottomMotorSpeed);
}



