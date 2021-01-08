#include <Autonomous/Auton.h>

Autonomous::Autonomous() : COREAuton("Test Auto") {}

void Autonomous::AddNodes() {
    std::cout << "running autonomous" << endl;
    m_drivePath = new Node(15, new PathFinderAction("example.wpilib.json"));
    // m_secondDrivePath = new Node(15, new PathFinderAction("foreward.wpilib.json"));
    AddFirstNode(m_drivePath);
    // m_drivePath->AddNext(m_secondDrivePath);
}
