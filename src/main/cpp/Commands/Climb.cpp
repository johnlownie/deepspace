#include "Commands/Climb.h"

Climb::Climb() {
  // Add Commands here:
  // e.g. AddSequential(new Command1());
  //      AddSequential(new Command2());
  // these will run in order.

  // To run multiple commands at the same time,
  // use AddParallel()
  // e.g. AddParallel(new Command1());
  //      AddSequential(new Command2());
  // Command1 and Command2 will run in parallel.

  // A command group will require all of the subsystems that each member
  // would require.
  // e.g. if Command1 requires chassis, and Command2 requires arm,
  // a CommandGroup containing them would require both the chassis and the
  // arm.


  AddParallel   ( new RaiseLegs (1.00, 5 ));
  AddParallel   ( new RaiseArms (0.63, 2 ));
  AddSequential ( new Crawl     (100,  12 ));
  AddSequential ( new Crawl(0,0.03));
  AddSequential ( new RaiseArms(-0.5, 0.5));
  AddSequential ( new EndClimb  (0.03     ));
}