#pragma once

#include <CORERobotLib.h>
#include <Robot.h>
#include "rev/ColorSensorV3.h"

using namespace CORE;

class ControlPanelSubsystem : public CORESubsystem {
public:
    ControlPanelSubsystem();
    void robotInit() override;
    void teleopInit() override;
    void teleop() override;
private:
    rev::ColorSensorV3 m_colorSensor{i2cPort};
};