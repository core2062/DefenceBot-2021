#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <CORERobotLib.h>
#include <DriveSubsystem.h>
#include <LauncherSubsystem.h>
#include <ClimberSubsystem.h>
#include <IntakeSubsystem.h>
#include <ConveyorSubsystem.h>
#include <Auton.h>

/* Drive ports */
#define RIGHT_FRONT_PORT 20
#define RIGHT_BACK_PORT 1
#define LEFT_FRONT_PORT 19
#define LEFT_BACK_PORT 32
#define INTAKE_PORT 14
#define CONVEYOR_1_PORT 15
#define CONVEYOR_2_PORT 16
#define TURRET_PORT 17


/* Solenoids */
#define LEFT_DRIVE_SHIFTER_PCM 1
#define RIGHT_DRIVE_SHIFTER_PCM 1
#define COMPRESSOR_PCM 2
#define LEFT_DRIVE_SHIFTER_HIGH_GEAR_PORT 0
#define RIGHT_DRIVE_SHIFTER_HIGH_GEAR_PORT 2 
#define LEFT_DRIVE_SHIFTER_LOW_GEAR_PORT 1
#define RIGHT_DRIVE_SHIFTER_LOW_GEAR_PORT 3
#define INTAKE_DOWN_PORT 4
#define INTAKE_UP_PORT 5


/* Launcher Ports */
#define TOP_LAUNCHER_MOTOR_PORT 15
#define BOTTOM_LAUNCHER_MOTOR_PORT 16

using namespace CORE;
using namespace std;

class Robot : public CORERobot {
public: 
 	Robot();
	void robotInit() override;
    void teleopInit() override;
    void teleop() override;
	void test() override;
	void testInit() override;
	static Robot * GetInstance();
	DriveSubsystem driveSubsystem;
	Autonomous controlledAutonomous;
private:
	static Robot * m_instance;
};