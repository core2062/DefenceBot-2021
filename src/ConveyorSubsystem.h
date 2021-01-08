#pragma once

#include <CORERobotLib.h>
#include <ctre/Phoenix.h>
#include "Config.h"
#include <frc2/command/SubsystemBase.h>

class ConveyorSubsystem : public CORESubsystem, public frc2::SubsystemBase {
public:
    ConveyorSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
    void setLowerMotor(double lowerConveyorSpeed);
    void setUpperMotor(double upperConveyorSpeed);

    COREConstant<double> lowerConveyorSpeed, upperConveyorSpeed;
private: 
    TalonSRX m_lowerConveyorMotor, m_frontConveyorMotor, m_backConveyorMotor;
};

