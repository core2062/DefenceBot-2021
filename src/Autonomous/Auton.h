#pragma once

#include <string>
#include <CORERobotLib.h>
#include <Autonomous/Actions/PathFinder.h>

using namespace CORE;
using namespace std;

class Autonomous: public COREAuton {
public:
    Autonomous();
    void AddNodes() override;
private:
    Node * m_drivePath;
    Node * m_secondDrivePath;
};