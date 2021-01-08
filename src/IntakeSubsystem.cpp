#include "IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem() : 
                                     m_intakeMotor(INTAKE_PORT), 
                                     m_intakeSolenoid(LEFT_DRIVE_SHIFTER_PCM, INTAKE_DOWN_PORT, INTAKE_UP_PORT),
                                     intakeSpeed("Intake Speed", 0.45){
}

void IntakeSubsystem::robotInit(){
    m_intakeMotor.Set(ControlMode::PercentOutput, 0);
    m_isIntakeDown = false;
    m_intakeMotor.SetInverted(true);
}

void IntakeSubsystem::teleopInit() {}

void IntakeSubsystem::teleop(){
    cout<<"Intake teleop"<<endl;
    if(operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::RIGHT_TRIGGER)){
       SetIntake(-intakeSpeed.Get());
    }
    else{
       SetIntake(0.0);
    }
    if (operatorJoystick->GetButton(CORE::COREJoystick::JoystickButton::RIGHT_BUTTON)) {
        SetIntake(intakeSpeed.Get());
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
