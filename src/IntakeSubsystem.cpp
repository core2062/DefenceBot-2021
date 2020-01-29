#include <IntakeSubsystem.h>
#include <Robot.h>

using namespace CORE;

IntakeSubsystem::IntakeSubsystem() : m_intakeMotor(INTAKE_PORT), 
                                     m_intakeSolenoid(LEFT_DRIVE_SHIFTER_PCM, INTAKE_DOWN_PORT, INTAKE_UP_PORT),
                                     m_intakeSpeed("Intake Speed", 0){

}

void IntakeSubsystem::robotInit(){
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);
    operatorJoystick->registerButton(CORE::COREJoystick::JoystickButton::LEFT_TRIGGER);
    operatorJoystick->registerButton(CORE::COREJoystick::JoystickButton::LEFT_BUTTON);
    m_isIntakeDown = false;
}

void IntakeSubsystem::teleopInit(){

}

void IntakeSubsystem::teleop(){
    if(operatorJoystick->getButton(CORE::COREJoystick::JoystickButton::LEFT_TRIGGER)){
       SetIntake(m_intakeSpeed.Get());
    }
    else{
       SetIntake(0.0);
    }
    if (operatorJoystick->getButton(CORE::COREJoystick::JoystickButton::LEFT_BUTTON)) {
        ToggleIntake();
    }
}

void IntakeSubsystem::SetIntake(double intakeSpeed) {
   m_intakeMotor.Set(ControlMode::PercentOutput, intakeSpeed); 
}
void IntakeSubsystem::ToggleIntake() {
    if(m_isIntakeDown) {
        m_intakeSolenoid.Set(frc::DoubleSolenoid::kForward);
    } else {
        m_intakeSolenoid.Set(frc::DoubleSolenoid::kReverse);
    }
}

using namespace CORE;
