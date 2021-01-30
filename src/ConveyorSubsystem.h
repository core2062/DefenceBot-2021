#pragma once

#include <CORERobotLib.h>
#include <ctre/Phoenix.h>
#include "Config.h"

class ConveyorSubsystem : public CORESubsystem {
public:
    COREConstant<double> conveyorSpeed;
    ConveyorSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
    void setMotor(double conveyorSpeed);

private: 
    TalonSRX m_conveyorMotor;
};

