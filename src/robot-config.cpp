#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor motor_R1 = motor(PORT1, ratio18_1, false);
motor motor_R2 = motor(PORT10, ratio18_1, false);
motor motor_L1 = motor(PORT11, ratio18_1, false);
motor motor_L2 = motor(PORT20, ratio18_1, false);
motor IntakeL = motor(PORT2, ratio18_1, false);
motor IntakeR = motor(PORT3, ratio18_1, false);
motor motor_liftL = motor(PORT12, ratio18_1, false);
motor motor_liftR = motor(PORT14, ratio18_1, false);
sonar Ranged = sonar(Brain.ThreeWirePort.A);
limit Limit = limit(Brain.ThreeWirePort.C);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}