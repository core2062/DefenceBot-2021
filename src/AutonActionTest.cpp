#include <AutonActionTest.h>
#include <Robot.h>

AutonomousAction1::AutonomousAction1() {}

void AutonomousAction1::ActionInit() {
	COREScheduler::teleopInit();
}

CORE::COREAutonAction::actionStatus AutonomousAction1::Action() {
	Robot::GetInstance()->driveSubsystem.setMotorSpeed(0.2, 0.2);
	return COREAutonAction::actionStatus::CONTINUE;
}

void AutonomousAction1::ActionEnd() {}

AutonomousAction2::AutonomousAction2() {}

void AutonomousAction2::ActionInit() {
	COREScheduler::teleopInit();
}

CORE::COREAutonAction::actionStatus AutonomousAction2::Action() {
	Robot::GetInstance()->driveSubsystem.setMotorSpeed(-0.2, -0.2);
	return COREAutonAction::actionStatus::CONTINUE;
}

void AutonomousAction2::ActionEnd() {}
