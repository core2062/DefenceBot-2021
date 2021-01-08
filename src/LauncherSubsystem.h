#pragma once

#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>
#include "Config.h"
#include <DriveSubsystem.h>
#include <frc2/command/SubsystemBase.h>

// using namespace frc;

class LauncherSubsystem : public CORESubsystem, public frc2::SubsystemBase {
public:
    LauncherSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
    void launcherOn(bool m_launcherOn);
private:
    TalonSRX m_launcherMotor;
    bool m_launcherOn;
    COREConstant<double> m_launcherSpeed;
};
