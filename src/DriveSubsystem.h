#pragma once

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <AHRS.h>
#include <CORERobotLib.h>
#include <COREFramework/COREScheduler.h>

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc2/command/SubsystemBase.h>
#include <Constants.h>
#include <iostream>
#include <COREUtilities/CORETimer.h>
#include "Config.h"

using namespace CORE;
using namespace frc;

enum class DriveSide{LEFT = 1, RIGHT = 2, BOTH = 3};

class DriveSubsystem : public CORESubsystem, public frc2::SubsystemBase {
public:
	DriveSubsystem();
	void robotInit() override;
	void teleopInit() override;
	void teleop() override;
	void Periodic() override;
	void teleopEnd() override;
	void auton();
	
	double getRobotPosition();
	void initTalons();
	void setMotorSpeed(double speedInFraction, DriveSide whichSide);
	void setMotorSpeed(double leftPercent, double rightPercent);
	void fillCompressor();
	void toggleGear();
	void resetEncoders();
	void resetOdometry(Pose2d pose);
	Pose2d getPose();
	double getStartHeading();
	double getHeading();
	double getTurnRate();
	void setMaxOutput(double maxOutput);
	double getAverageEncoderDistance();
	void tankDriveVolts(units::volt_t l, units::volt_t r);
	WPI_TalonSRX& getRightMaster();
	WPI_TalonSRX& getLeftMaster();
	WPI_TalonSRX& getRightSlave();
	WPI_TalonSRX& getLeftSlave();
	void setVelocity(double leftVelocity, double rightVelocity);
	DifferentialDriveWheelSpeeds getWheelSpeeds();

	DifferentialDriveOdometry m_odometry;
	COREConstant<double> m_driveTurnkP;
	COREVector path;

private:
	double m_wheelCircumference = 0.4787787204;
	WPI_TalonSRX m_leftMaster, m_rightMaster, m_leftSlave, m_rightSlave;
	SpeedControllerGroup m_leftMotors{m_leftSlave, m_leftMaster};
	SpeedControllerGroup m_rightMotors{m_rightSlave, m_rightMaster};
	DifferentialDrive m_drive{m_leftMotors, m_rightMotors};
    COREConstant<double> m_etherAValue, m_etherBValue, m_etherQuickTurnValue, m_ticksPerInch;
    DoubleSolenoid m_leftDriveShifter, m_rightDriveShifter;
    bool m_highGear;
    Compressor compressor;
	double m_wheelbase = 20.8;
	double m_trackwidth = 25.881;
	AHRS * m_gyro;
    int count = 0;
};
