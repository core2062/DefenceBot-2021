#pragma once

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>
#include "Config.h"

using namespace CORE;
using namespace frc;

enum class DriveSide{LEFT = 1, RIGHT = 2, BOTH = 3};

class LauncherSubsystem : public CORESubsystem, public frc2::SubsystemBase {
public:
	LauncherSubsystem();
	void robotInit() override;
	void teleopInit() override;
	void teleop() override;
	void Periodic() override;
	void teleopEnd() override;
	void auton();
	void initTalons();


private:

};
