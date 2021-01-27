#pragma once

#include <string>
#include <iostream>
#include <frc/RobotBase.h>
#include <frc/TimedRobot.h>
#include <CORERobotLib.h>
#include <COREFramework/COREScheduler.h>

#include "Config.h"
#include "DriveSubsystem.h"
#include "ConveyorSubsystem.h"
#include "LauncherSubsystem.h"
#include "ClimberSubsystem.h"

using namespace CORE;
using namespace std;

class Robot : public CORERobot {
public: 
 	Robot();
	void RobotPeriodic() override;
	void TeleopPeriodic() override;
	void robotInit() override;
    void teleopInit() override;
    void teleop() override;
	void test() override;
	void testInit() override;
	static Robot * GetInstance();
	DriveSubsystem driveSubsystem;
	ClimberSubsystem ClimberSubsystem;
	ConveyorSubsystem ConveyorSubsystem;
	LauncherSubsystem LauncherSubsystem;

private:
  	frc2::Command* m_autonomousCommand = nullptr;
	static Robot * m_instance;
};
