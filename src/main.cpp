// To complete the VEXcode V5 Text project upgrade process, please follow the
// steps below.
// 
// 1. You can use the Robot Configuration window to recreate your V5 devices
//   - including any motors, sensors, 3-wire devices, and controllers.
// 
// 2. All previous code located in main.cpp has now been commented out. You
//   will need to migrate this code to the new "int main" structure created
//   below and keep in mind any new device names you may have set from the
//   Robot Configuration window. 
// 
// If you would like to go back to your original project, a complete backup
// of your original (pre-upgraded) project was created in a backup folder
// inside of this project's folder.

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
}

// // ---- START VEXCODE CONFIGURED DEVICES ----
// // Robot Configuration:
// // [Name]               [Type]        [Port(s)]
// // ---- END VEXCODE CONFIGURED DEVICES ----
// /*----------------------------------------------------------------------------*/
// /*                                                                            */
// /*    Module:       main.cpp                                                  */
// /*    Author:       C:\Users\quads                                            */
// /*    Created:      Wed Sep 04 2019                                           */
// /*    Description:  V5 project                                                */
// /*                                                                            */
// /*----------------------------------------------------------------------------*/
 #include "vex.h"
 #include "robot-config.h"
 #include "visionconfig.h"
// 
 using namespace vex;
 using namespace std;
// 
 // gloabal variables
 static int count  = 0;
// 
 // functions go here
 void disp() {
 Brain.Screen.printAt( 20, 50, "What's Poppin' Gang Gang? %d", count++);
 };
 
// // define your global instances of motors and other devices here
 int main() {
     while (true) {
         motor_L1.spin(directionType::fwd, (controlmain.Axis3.value() + controlmain.Axis4.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
 	      motor_R1.spin(directionType::fwd, (controlmain.Axis3.value() - controlmain.Axis4.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
         motor_L2.spin(directionType::fwd, (controlmain.Axis3.value() + controlmain.Axis4.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
 	      motor_R2.spin(directionType::fwd, (controlmain.Axis3.value() - controlmain.Axis4.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
// // waits 10ms befroe update and allow other tasks to run
         task::sleep(10);
         //disp();
     }  
};
// 