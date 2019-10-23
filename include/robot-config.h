using namespace vex;

extern brain Brain;

// VEXcode devices

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

vex::brain Brain;

vex::motor motor_L1 (vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor motor_R1 (vex::PORT11, vex::gearSetting::ratio18_1, true);
vex::motor motor_L2 (vex::PORT10, vex::gearSetting::ratio18_1, false);
vex::motor motor_R2 (vex::PORT20, vex::gearSetting::ratio18_1, true);
vex::controller controlmain = vex::controller();