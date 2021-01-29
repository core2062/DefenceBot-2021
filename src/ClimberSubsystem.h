#pragma once

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>
#include "Config.h"

using namespace CORE;
using namespace frc;

class ClimberSubsystem : public CORESubsystem, public frc2::SubsystemBase {
public:
	ClimberSubsystem();
	void robotInit() override;
	void teleopInit() override;
	void teleop() override;
	void Periodic() override;
	void teleopEnd() override;
	void auton();
	void initTalons();


private:
	TalonSRX m_stiltOne;
	TalonSRX m_stiltTwo;
	TalonSRX m_stiltThree;
	TalonSRX m_stiltFour;
	bool m_isClimbed;
};
