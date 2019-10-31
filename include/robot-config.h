using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor motor_R1;
extern motor motor_R2;
extern motor motor_L1;
extern motor motor_L2;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );