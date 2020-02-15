// #pragma once

// #include <CORERobotLib.h>
// #include <frc/DoubleSolenoid.h>
// #include <ctre/Phoenix.h>
// #include <Robot.h>

// using namespace CORE;
// using namespace frc;

// class IntakeSubsystem : public CORESubsystem {
// public:
//     IntakeSubsystem();
//     void robotInit() override;
//     void teleopInit() override;
//     void teleop() override;
//     void SetIntake(double intakeSpeed);
//     void ToggleIntake();
// private:
//     TalonSRX m_intakeMotor;
//     DoubleSolenoid m_intakeSolenoid;
//     COREConstant<double> m_intakeSpeed;
//     bool m_isIntakeDown;
// };