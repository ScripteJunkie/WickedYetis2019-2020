#include "autonomous-config.h"
#include <iomanip> 
#include <iostream> 
#include <stdlib.h> 
#include <unistd.h>
using namespace std;

void autonomousboiii( void ) {
  #include "visionconfig.h"
  
  int seconds = 0;
  //driveForward( 2 * 12 ); // drive forwards
  //driveForward(-2 * 12 ); // drive backwards
 // while (true){
    motor_L1.spin(directionType::fwd, -100, velocityUnits::pct);
    motor_R1.spin(directionType::fwd, 100, velocityUnits::pct);
    motor_L2.spin(directionType::fwd, -100, velocityUnits::pct); 
    motor_R2.spin(directionType::fwd, 100, velocityUnits::pct);
    vex::task::sleep(4000);
    motor_L1.spin(directionType::rev, -100, velocityUnits::pct);
    motor_R1.spin(directionType::rev, 100, velocityUnits::pct);
    motor_L2.spin(directionType::rev, -100, velocityUnits::pct); 
    motor_R2.spin(directionType::rev, 100, velocityUnits::pct);
    vex::task::sleep(1000);
    //sleep(1);
   // seconds++;
    if (seconds < 10) {
      motor_L1.stop(vex::brakeType::coast);
      motor_R1.stop(vex::brakeType::coast);
      motor_L2.stop(vex::brakeType::coast); 
      motor_R2.stop(vex::brakeType::coast);
    }
  };
//}