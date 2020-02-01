#pragma once

#include <CORERobotLib.h>
#include <ctre/Phoenix.h>
#include <Robot.h>

using namespace frc;

class LauncherSubsystem : public CORESubsystem {
public:
    LauncherSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
private:
    TalonSRX m_topMotor, m_bottomMotor;
    double m_topMotorSpeed, m_bottomMotorSpeed;
};