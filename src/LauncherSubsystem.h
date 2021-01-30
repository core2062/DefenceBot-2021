#pragma once

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>
#include "Config.h"

using namespace CORE;
using namespace frc;

enum class DriveSide{LEFT = 1, RIGHT = 2, BOTH = 3};

class launcherSubsystem : public CORESubsystem/*, public frc2::SubsystemBase */{
public:
	void LauncherSubsystem();
	void robotInit() override;
	void teleopInit() override;
	void teleop() override;
	void teleopEnd() override;
	void auton();
	void initTalons();


private:

};
