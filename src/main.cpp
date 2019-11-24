#include "vex.h"
#include "autonomous.h"
#include "robot-config.h"

using namespace vex;
vex::competition Competition;

 
 // gloabal variables
//int count = 0;

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
  autonomousboiii();
  disp();
}



void usercontrol( void ) {
  while (true) {
        Brain.Screen.printAt(1, 60, "distance: %f cm", Ranged.distance(distanceUnits::cm));
        Brain.Screen.newLine();
        Brain.Screen.printAt(1, 50, "Limitpressed: %f", Limit.pressing());
        motor_L1.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
 	      motor_R1.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
        motor_L2.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
 	      motor_R2.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;

        if (Controller1.ButtonL2.pressing()) {
          motor_liftL.spin(directionType::fwd, 5, velocityUnits::pct);
          task::sleep(20);
        }
        else {
          motor_liftL.stop(vex::brakeType::brake);
        }

        if (Controller1.ButtonL1.pressing()) {
          motor_liftL.spin(directionType::rev, 5, velocityUnits::pct);
          task::sleep(20);
        }
        else {
          motor_liftL.stop(vex::brakeType::brake);
        }
        
        if (Controller1.ButtonR2.pressing()) {
          IntakeL.spin(directionType::fwd, 100, velocityUnits::pct);
          IntakeR.spin(directionType::rev, 100, velocityUnits::pct);
          task::sleep(20);
        }
        else {
          IntakeL.stop(vex::brakeType::coast);
          IntakeR.stop(vex::brakeType::coast);

        }

        if (Controller1.ButtonR1.pressing()) {
          IntakeL.spin(directionType::rev, 100, velocityUnits::pct);
          IntakeR.spin(directionType::fwd, 100, velocityUnits::pct);
          task::sleep(20);
        }
        else {
          IntakeL.stop(vex::brakeType::coast);
          IntakeR.stop(vex::brakeType::coast);
        }

       // if (Controller1.ButtonUp.pressing()) {
         // motor_liftL.spin(directionType::rev, 5, velocityUnits::pct);
       // }
       // else if (Controller1.ButtonDown.pressing()) {
        //  motor_liftL.spin(directionType::fwd, 5, velocityUnits::pct);
       // }
        // waits 10ms befroe update and allow other tasks to run
        //task::sleep(10);
         //disp();
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




//motor motor_R1 = motor(PORT1, ratio18_1, false);
//motor motor_R2 = motor(PORT10, ratio18_1, false);
//motor motor_L1 = motor(PORT11, ratio18_1, false);
//motor motor_L2 = motor(PORT20, ratio18_1, false);
//controller Controller1 = controller(primary);
//motor IntakeL = motor(PORT2, ratio18_1, false);
//motor IntakeR = motor(PORT3, ratio18_1, false);
//vex::motor motor_liftL = motor(PORT12, ratio18_1, false);
//vex::motor motor_liftR = motor(PORT14, ratio18_1, false);
//sonar RangeFind = sonar(Brain.ThreeWirePort.A);
//vex::sonar sonar1 = Sonar(Brain.ThreeWirePort.A);