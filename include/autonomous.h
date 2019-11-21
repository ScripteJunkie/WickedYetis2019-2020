#include "autonomous-config.h"

void autonomousboiii( void ) {
  #include "visionconfig.h"
  
int i = 0;
  //driveForward( 2 * 12 ); // drive forwards
  //driveForward(-2 * 12 ); // drive backwards
  while (i < 500) {
    motor_L1.spin(directionType::fwd, 20, velocityUnits::pct);
    motor_R1.spin(directionType::fwd, -20, velocityUnits::pct);
    motor_L2.spin(directionType::fwd, 20, velocityUnits::pct); 
    motor_R2.spin(directionType::fwd, -20, velocityUnits::pct);
    i++;
      if (Limit.pressing() == true) {
        motor_L1.setBrake(brakeType::brake);
        motor_L2.setBrake(brakeType::brake);
        motor_R1.setBrake(brakeType::brake);
        motor_R2.setBrake(brakeType::brake);
      }
    task::sleep(100);
  }
}