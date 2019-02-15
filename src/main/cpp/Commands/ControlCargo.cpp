#include "Commands/ControlCargo.h"
#include "Robot.h"

ControlCargo::ControlCargo() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_Flap);
  this->pJoyOp = Robot::m_oi->GetJoystickOperator();
}

// Called just before this Command runs the first time
// aka: every time teleop is enabled
void ControlCargo::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ControlCargo::Execute() {

  // Control piston
  if(this->pJoyOp->GetTriggerAxis(Hand::kLeftHand) > 0.8){
    Robot::m_Piston->Deploy();
  }else{
    Robot::m_Piston->Retract();
  }
}


bool ControlCargo::IsFinished() { return false; }

// Called once after isFinished returns true
void ControlCargo::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlCargo::Interrupted() {}