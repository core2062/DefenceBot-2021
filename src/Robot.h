#pragma once

#include <string>

#include <frc/WPILib.h>
#include <CORERobotLib.h>
#include <DriveSubsystem.h>

/* Drive Motor Ports */
//Right Front Drive Motor
#define RIGHT_FRONT_PORT 1
//Right Back Drive Motor
#define RIGHT_BACK_PORT 2
//Left Front Drive Motor
#define LEFT_FRONT_PORT 3
//Left Back Drive Motor
#define LEFT_BACK_PORT 4

/* Solenoids */
// Drive 
#define DRIVE_SHIFTER_PCM 0
#define COMPRESSOR_PCM 0

#define DRIVE_SHIFTER_HIGH_GEAR_PORT 6
#define DRIVE_SHIFTER_LOW_GEAR_PORT 7

using namespace CORE;
using namespace std;

class Robot : public CORERobot {
public: 
 	Robot();
	void robotInit() override;
    void teleopInit() override;
    void teleop() override;
	void test() override;
	static Robot * GetInstance();

	DriveSubsystem driveSubsystem;

private:
	static Robot * m_instance;
};
