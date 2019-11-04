// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// motor_L2             motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// motor_L1             motor         11              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// motor_R2             motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motor_R1             motor         1               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    20, 10          
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
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
#include "api.h"

using namespace vex;

//int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
//  vexcodeInit();
  
//}

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
// #include "vex.h"
// #include "robot-config.h"

// #include "visionconfig.h"
// 
// using namespace vex;
// using namespace std;
// 
 // gloabal variables
int count = 0;

// 
 // functions go here
 void disp() {
 Brain.Screen.printAt( 20, 50, "Wow");
 };
 

const float WHEEL_DIAMETER = 4.125; // inches
const float WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * 3.1416;
const float GEAR_RATIO = 0.5; // 0.5 turn of motor = 1 turn of wheel
const int  AUTON_DRIVE_PCT = 50; // motors at 50% power during auton
const float TURNING_DIAMETER = 19;

void driveForward( float inches ) {
    float inchesPerDegree = WHEEL_CIRCUMFERENCE / 360;
    float degrees = inches / inchesPerDegree;
    // startRotate doesn't wait for completion
    // this way, the other wheel can turn at same time
    motor_L1.startRotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
    motor_R1.rotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
    motor_L2.startRotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
    motor_R2.rotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
}

void turn( float degrees ) {
    // Note: +90 degrees is a right turn
    float turningRatio = TURNING_DIAMETER / WHEEL_DIAMETER;
    float wheelDegrees = turningRatio * degrees;    
    // Divide by two because each wheel provides half the rotation
    motor_L1.startRotateFor(
        wheelDegrees * GEAR_RATIO / 2, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
    motor_R1.rotateFor(
        wheelDegrees * GEAR_RATIO / 2, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
        motor_L2.startRotateFor(
        wheelDegrees * GEAR_RATIO / 2, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
    motor_R2.rotateFor(
        wheelDegrees * GEAR_RATIO / 2, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
} 

 void autonomous( void ) {
#include "visionconfig.h"
    driveForward( 1.2 * 12 ); // drive 1.2 ft forwards
    driveForward(-1.2 * 12 ); // drive 1.2 ft backwards

}
// // define your global instances of motors and other devices here
 int main() {
    autonomous();
     while (true) {
        motor_L1.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
 	      motor_R1.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
        motor_L2.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
 	      motor_R2.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
        // waits 10ms befroe update and allow other tasks to run
        task::sleep(10);
         //disp();
     }  
};
