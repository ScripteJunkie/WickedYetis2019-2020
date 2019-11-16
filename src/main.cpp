// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// motor_liftL          motor         12              
// IntakeL              motor         2               
// IntakeR              motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// motor_liftL          motor         12              
// IntakeL              motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// motor_liftL          motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// Motor_12             motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// Motor_12             motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// Motor12              motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
//#include "autonomous.h"
using namespace vex;
vex::competition Competition;
 
 // gloabal variables
int count = 0;

// functions go here
 void disp() {
 Brain.Screen.printAt( 20, 50, "Please Help!");
 Brain.Screen.newLine();

 };

 void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}


void autonomous( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}



void usercontrol( void ) {
  while (true) {
        motor_L1.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
 	      motor_R1.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
        motor_L2.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
 	      motor_R2.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;

        if (Controller1.ButtonL2.pressing()) {
          motor_liftL.spin(directionType::fwd, 5, velocityUnits::pct);
          task::sleep(30);
        }
        else {
          motor_liftL.setBrake(brakeType::brake);
        }
                if (Controller1.ButtonL1.pressing()) {
          motor_liftL.spin(directionType::rev, 5, velocityUnits::pct);
          task::sleep(30);
        }
        else {
          motor_liftL.setBrake(brakeType::brake);
        }
        if (Controller1.ButtonR2.pressing()) {
          IntakeL.spin(directionType::fwd, 10, velocityUnits::pct);
          IntakeR.spin(directionType::rev, 10, velocityUnits::pct);
        }
        if (Controller1.ButtonR1.pressing()) {
          IntakeL.spin(directionType::rev, 10, velocityUnits::pct);
          IntakeR.spin(directionType::fwd, 10, velocityUnits::pct);
        }
        // waits 10ms befroe update and allow other tasks to run
        task::sleep(10);
         //disp();
     }  
       if (Controller1.ButtonUp.pressing()) {
          motorliftR.spin(directionType::fwd, 5, velocityUnits::pct);
        }
      if (Controller1.ButtonDown.pressing()) {
          motor_liftR.spin(directionType::rev, 5, velocityUnits::pct);
        }
}

// define your global instances of motors and other devices here
 int main() {
   //autonomous();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
}

};
