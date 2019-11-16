#include "autonomous-config.h"

void autonomous( void ) {
  #include "visionconfig.h"
  
  //driveForward( 2 * 12 ); // drive forwards
  //driveForward(-2 * 12 ); // drive backwards
  motor_L1.spin(directionType::fwd, 10, velocityUnits::pct);
  motor_R1.spin(directionType::fwd, -10, velocityUnits::pct);
  motor_L2.spin(directionType::fwd, 10, velocityUnits::pct); 
  motor_R2.spin(directionType::fwd, -10, velocityUnits::pct);
}