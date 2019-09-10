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

// define your global instances of motors and other devices here
int main() {
    int count = 0;
   
    while(1) {
        Brain.Screen.printAt( 20, 50, "What's Poppin' Gang Gang? %d", count++ );
        // Allow other tasks to run
        this_thread::sleep_for(10);
      if (count == 500) {
       break;
      }
    }

    while (true) {
        motor_L1.spin(directionType::fwd, (controlmain.Axis3.value() + controlmain.Axis1.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
	      motor_R1.spin(directionType::fwd, (controlmain.Axis3.value() - controlmain.Axis1.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
        task::sleep(20);
    }  

}
