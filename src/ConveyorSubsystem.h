#pragma once

#include <CORERobotLib.h>
#include <ctre/Phoenix.h>
#include "Config.h"

class ConveyorSubsystem : public CORESubsystem {
public:
    ConveyorSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
    void setLowerMotor(double lowerConveyorSpeed);
    void setUpperMotor(double upperConveyorSpeed);

private: 
    TalonSRX m_lowerConveyorMotor, m_frontConveyorMotor, m_backConveyorMotor;
    COREConstant<double> m_lowerConveyorSpeed, m_upperConveyorSpeed;
};

