#include "LauncherSubsystem.h"

LauncherSubsystem::LauncherSubsystem() :
		
}

void LauncherSubsystem::robotInit() {
    initTalons();

}

void LauncherSubsystem::teleopInit() {
	initTalons();
}

void LauncherSubsystem::teleop() {

}

void LauncherSubsystem::setMotorSpeed(double speedInFraction, DriveSide whichSide) {

}

void LauncherSubsystem::initTalons() {

}

void LauncherSubsystem::teleopEnd() {
	
}
