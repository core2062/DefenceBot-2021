#pragma once

#include <frc/DoubleSolenoid.h>
#include <CORERobotLib.h>
#include "Config.h"
#include <frc2/command/SubsystemBase.h>

using namespace CORE;
using namespace frc;

class ClimberSubsystem : public CORESubsystem {
public:
    ClimberSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;

private:

};
