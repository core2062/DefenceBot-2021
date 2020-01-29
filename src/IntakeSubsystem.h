#pragma once


using namespace CORE;

class IntakeSubsystem : public CORESubsystem {
public:

IntakeSubsystem();

void robotInit() override;
void teleopInit() override;
void teleop() override;

private:


}