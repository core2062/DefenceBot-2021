#pragma once

#include <CORERobotLib.h>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <Robot.h>

class ConveyorSubsystem : public CORESubsystem {
public:
    ConveyorSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
    void setMotor(double conveyorSpeed);

private: 
    TalonSRX m_conveyorMotor1, m_conveyorMotor2;
    COREConstant<double> m_conveyorSpeed;
};

