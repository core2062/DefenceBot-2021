#pragma once

#include <string>
#include <iostream>
#include <frc/RobotBase.h>
#include <frc/TimedRobot.h>
#include <CORERobotLib.h>
#include <COREFramework/COREScheduler.h>
#include "ClimberSubsystem.h"
#include "ConveyorSubsystem.h"
#include "DriveSubsystem.h"
#include "IntakeSubsystem.h"
#include "LauncherSubsystem.h"
#include "TurretSubsystem.h"
#include "Config.h"
#include "TestRoutine.h"
#include "DriveRoutine.h"
#include "ThreeBallRoutine.h"
#include "RobotContainer.h"
#include "Autonomous/Auton.h"

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
	LauncherSubsystem launcherSubsystem;
	IntakeSubsystem intakeSubsystem;
	TurretSubsystem turretSubsystem;
	ConveyorSubsystem conveyorSubsystem;
	TestRoutine testRoutine;
	DriveRoutine driveRoutine;
	ThreeBallRoutine threeBallRoutine;
	ClimberSubsystem climberSubsystem;
	RobotContainer robotContainer;
	Autonomous autonomous;

private:
  	frc2::Command* m_autonomousCommand = nullptr;
	static Robot * m_instance;
};
