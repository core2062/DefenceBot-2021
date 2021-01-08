#pragma once

#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/PIDCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/SmallString.h>
#include <frc/Filesystem.h>
#include <wpi/Path.h>

#include "Constants.h"
#include "DriveSubsystem.h"
#include "ClimberSubsystem.h"
#include "ConveyorSubsystem.h"
#include "DriveSubsystem.h"
#include "IntakeSubsystem.h"
#include "LauncherSubsystem.h"
#include "TurretSubsystem.h"
#include "CORERobotLib.h"

using namespace CORE;

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand(std::string path);

 private:

  // The robot's subsystems and commands are defined here...

  // The robot's subsystems
  DriveSubsystem m_drive;
  IntakeSubsystem m_intake;
  TurretSubsystem m_turret;
  ConveyorSubsystem m_conveyor;
  ClimberSubsystem m_climber;
  LauncherSubsystem m_launcher;
  // The chooser for the autonomous routines
  frc::SendableChooser<frc2::Command*> m_chooser;
};
