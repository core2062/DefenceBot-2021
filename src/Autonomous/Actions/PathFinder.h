
#pragma once

#include "CORERobotLib.h"
#include <string>
#include <frc2/command/Command.h>

using namespace CORE;

class PathFinderAction : public COREAutonAction {
public:
    explicit PathFinderAction(std::string path);
    void ActionInit() override;
    actionStatus Action() override;
    void ActionEnd() override;
private:
    std::string m_path;
    frc2::Command* m_autonomousCommand = nullptr;
};