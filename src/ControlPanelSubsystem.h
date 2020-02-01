#pragma once

#include <CORERobotLib.h>
#include <Robot.h>

using namespace CORE;

class ControlPanelSubsystem : public CORESubsystem {
public:
    ControlPanelSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
private:
};