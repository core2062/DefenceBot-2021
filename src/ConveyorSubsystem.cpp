#include "ConveyorSubsystem.h"

ConveyorSubsystem::ConveyorSubsystem() :
		
}

void ConveyorSubsystem::robotInit() {
    initTalons();

ConveyorSubsystem::ConveyorSubsystem() : conveyorSpeed("Conveyor Speed", 0.75),
                                         m_conveyorMotor(CONVEYOR_1_PORT) {
}

void ConveyorSubsystem::robotInit(){
    /* Inits Talons */
    m_conveyorMotor.Set(ControlMode::PercentOutput, 0);
    m_conveyorMotor.SetInverted(true);
}

void ConveyorSubsystem::teleopInit() {

}

void ConveyorSubsystem::teleop(){
    cout<<"Conveyer teleop"<<endl;
    if(operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::LEFT_TRIGGER)) {
        setMotor(conveyorSpeed.Get());
    } else if(operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::LEFT_BUTTON)) {
        setMotor(-conveyorSpeed.Get());
    } else {
        setMotor(0.0);
    }
   
}

void ConveyorSubsystem::setMotor(double conveyorSpeed){
    m_conveyorMotor.Set(ControlMode::PercentOutput, conveyorSpeed); 
}
