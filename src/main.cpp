/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\quads                                            */
/*    Created:      Wed Sep 04 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "api.h"

using namespace vex;
using namespace std;

// gloabal variables
static int count  = 0;

// functions go here
void disp() {
  Brain.Screen.printAt( 20, 50, "What's Poppin' Gang Gang? %d", count++);
};

// define your global instances of motors and other devices here
int main() {
    while (true) {
        motor_L1.spin(directionType::fwd, (controlmain.Axis3.value() + controlmain.Axis4.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
	      motor_R1.spin(directionType::fwd, (controlmain.Axis3.value() - controlmain.Axis4.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
// waits 10ms befroe update and allow other tasks to run
        task::sleep(10);
        disp();
    }  
};
