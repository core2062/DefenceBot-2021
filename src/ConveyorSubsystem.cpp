// #include <ConveyorSubsystem.h>

// using namespace CORE;

// ConveyorSubsystem::ConveyorSubsystem() : m_conveyorMotor1(CONVEYOR_1_PORT),
//                                          m_conveyorMotor2(CONVEYOR_2_PORT),
//                                          m_conveyorSpeed("Conveyor Speed", 0){
                                         
// }

// void ConveyorSubsystem::robotInit(){
//     m_conveyorMotor1.Set(ControlMode::PercentOutput, 0);
//     m_conveyorMotor2.Set(ControlMode::PercentOutput, 0);
//     m_conveyorMotor1.SetInverted(true);
//     m_conveyorMotor2.SetInverted(false);
//     operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER);
//     operatorJoystick->RegisterButton(CORE::COREJoystick::JoystickButton::RIGHT_BUTTON);
// }

// void ConveyorSubsystem::teleopInit(){

// }

// void ConveyorSubsystem::teleop(){
//     if(operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER)) {
//         setMotor(m_conveyorSpeed.Get());
//     } else if(operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::RIGHT_BUTTON)) {
//         setMotor(-m_conveyorSpeed.Get());
//     } else {
//         setMotor(0.0);
//     }
// }

// void ConveyorSubsystem::setMotor(double conveyorSpeed){
//     m_conveyorMotor1.Set(ControlMode::PercentOutput, conveyorSpeed); 
//     m_conveyorMotor2.Set(ControlMode::PercentOutput, conveyorSpeed);
// }
