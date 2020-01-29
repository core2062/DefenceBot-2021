#pragma once

#include <CORERobotLib.h>
#include <Robot.h>

using namespace CORE;

class ClimberSubsystem : public CORESubsystem {
public:
    ClimberSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
private:
};
