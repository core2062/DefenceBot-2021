#include <Robot.h>

Robot* Robot::m_instance;

Robot::Robot() {
	m_instance = this;
}

void Robot::robotInit() {
	wpi::SmallString<64> deployDirectory;
    frc::filesystem::GetDeployDirectory(deployDirectory);
    wpi::sys::path::append(deployDirectory, "paths");
    wpi::sys::path::append(deployDirectory, "foreward.wpilib.json");

    wpi::SmallString<64> deployDirectory1;
    frc::filesystem::GetDeployDirectory(deployDirectory1);
    wpi::sys::path::append(deployDirectory1, "paths");
    wpi::sys::path::append(deployDirectory1, "foreward.wpilib.json");
    frc::Trajectory trajectory1 = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory1);
    frc::Trajectory trajectory2 = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);
    frc::Trajectory trajectory = trajectory2;
}

void Robot::RobotPeriodic() {
    frc2::CommandScheduler::GetInstance().Run();
}

void Robot::TeleopPeriodic() {
}

void Robot::teleopInit() {}

void Robot::test() {}

void Robot::teleop() {
    cout<<"RobotTeleop"<<endl;
}

void Robot::testInit() {
  
}

Robot * Robot::GetInstance() {
	return m_instance;
}

#ifndef RUNNING_FRC_TESTS
int main() {
	return frc::StartRobot<Robot>();
}
#endif
