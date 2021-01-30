#include "ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem():
		m_stiltOne  (STILT_1_PORT),
		m_stiltTwo  (STILT_2_PORT),
		m_stiltThree(STILT_3_PORT),
		m_stiltFour (STILT_4_PORT)
{}

void ClimberSubsystem::robotInit() {
    initTalons();
}

void ClimberSubsystem::teleopInit() {
	initTalons();
}

void ClimberSubsystem::teleop() {

}

void ClimberSubsystem::initTalons() {
	m_stiltOne  .Set(ControlMode::PercentOutput, 0);
	m_stiltTwo  .Set(ControlMode::PercentOutput, 0);
	m_stiltThree.Set(ControlMode::PercentOutput, 0);
	m_stiltFour .Set(ControlMode::PercentOutput, 0);
}

void ClimberSubsystem::teleopEnd() {
	
}