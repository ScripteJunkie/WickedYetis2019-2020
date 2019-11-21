using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor motor_R1;
extern motor motor_R2;
extern motor motor_L1;
extern motor motor_L2;
extern motor IntakeL;
extern motor IntakeR;
extern motor motor_liftL;
extern motor motor_liftR;
extern sonar Ranged;
extern limit Limit;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );