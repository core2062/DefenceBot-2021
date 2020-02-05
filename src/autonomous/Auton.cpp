#include <Autonomous/Auton.h>

Autonomous::Autonomous() : COREAuton("Test Auto") {}

void Autonomous::AddNodes() {
    autonNode1 = new Node(5, new AutonomousAction1());
    autonNode2 = new Node(5, new AutonomousAction2());
    AddFirstNode(autonNode1);
    autonNode1->AddNext(autonNode2);
}
