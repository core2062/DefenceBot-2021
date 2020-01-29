#pragma once


using namespace CORE;

class LauncherSubsystem : public CORESubsystem {
public:

LauncherSubsystem();

void robotInit() override;
void teleopInit() override;
void teleop() override;

private:


}