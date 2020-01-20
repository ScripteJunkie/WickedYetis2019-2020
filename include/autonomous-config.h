#include "api.h"

/*
  Gear ratio is different between the front and back motors. Rear motors run 1 to 1, while front run around 2 to 1.
  This means there is a difference between the absolute rotation of the front and rear wheels (Not yet accounted for in the program).
  Motor power is also adustable and might be changed based on enviroment variables.
  Statements must be added to add intake and lift functionality.

*/

const float WHEEL_DIAMETER = 4.000; // inches
const float WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * 3.1416;
const float GEAR_RATIO = 0.5; // 0.5 turn of motor = 1 turn of wheel
const int  AUTON_DRIVE_PCT = 100; // motors at 100% power during auton
const float TURNING_DIAMETER = 1; //19 and dont set to 0 you fucking idiot
const float ttime = 100;

void drive( float inches) {
    float inchesPerDegree = WHEEL_CIRCUMFERENCE / 360;
    float degrees = (inches * 3) / inchesPerDegree;
    // startRotate doesn't wait for completion
    // this way, the other wheel can turn at same time
    motor_L1.rotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R1.rotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_L2.rotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R2.rotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, true
    );
    task::sleep(ttime);
    
}

void turnLeft( float degrees ) {
    // +90 degrees is a right turn
    float turningRatio = TURNING_DIAMETER / WHEEL_DIAMETER;
    float wheelDegrees = /*turningRatio * */ degrees * 12.222;    
    // incorrect gearing --> 1/2 because each wheel provides half the rotation <--
    // get rid of '/2'
    // maybe just rotateFor with a false at the end but need to try both
    motor_L1.rotateFor(
        -wheelDegrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R1.rotateFor(
        wheelDegrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_L2.rotateFor(
        -wheelDegrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R2.rotateFor(
        wheelDegrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, true
    );
  task::sleep(ttime);
} 

void turnRight( float degrees ) {
    // +90 degrees is a right turn
    float turningRatio = TURNING_DIAMETER / WHEEL_DIAMETER;
    float wheelDegrees = /*turningRatio * */ degrees * 12.222;    
    // incorrect gearing --> 1/2 because each wheel provides half the rotation <--
    // get rid of '/2'
    // maybe just rotateFor with a false at the end but need to try both
    motor_L1.rotateFor(
        wheelDegrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R1.rotateFor(
        -wheelDegrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_L2.rotateFor(
        wheelDegrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R2.rotateFor(
        -wheelDegrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, true
    );
  task::sleep(ttime);
} 

void arcleft( float degrees, float radius ) {
  float arcLength = radius * degrees * (3.1416/180);
  float baseRatio = 1 + (18/radius);

    motor_L1.rotateFor(
        360 * arcLength / WHEEL_CIRCUMFERENCE , vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R1.rotateFor(
        (360 * arcLength / WHEEL_CIRCUMFERENCE) * baseRatio , vex::rotationUnits::deg,
        AUTON_DRIVE_PCT * baseRatio, vex::velocityUnits::pct, false
    );
    motor_L2.rotateFor(
        360 * arcLength / WHEEL_CIRCUMFERENCE , vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R2.rotateFor(
        (360 * arcLength / WHEEL_CIRCUMFERENCE) * baseRatio , vex::rotationUnits::deg,
        AUTON_DRIVE_PCT * baseRatio, vex::velocityUnits::pct, false
    );
  task::sleep(ttime);
}

void arcright( float degrees, float radius ) {
  float arcLength = radius * degrees * (3.1416/180);
  float baseRatio = 1 + (18/radius);

    motor_L1.rotateFor(
        (360 * arcLength / WHEEL_CIRCUMFERENCE) * baseRatio , vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT * baseRatio, vex::velocityUnits::pct, false
    );
    motor_R1.rotateFor(
        360 * arcLength / WHEEL_CIRCUMFERENCE , vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_L2.rotateFor(
        (360 * arcLength / WHEEL_CIRCUMFERENCE) * baseRatio , vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT * baseRatio, vex::velocityUnits::pct, false
    );
    motor_R2.rotateFor(
        360 * arcLength / WHEEL_CIRCUMFERENCE , vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
  task::sleep(ttime);
}

/*
void lift( float absposition ) {
  if ( absposition == true ) {
    //lift up
  }
  else {
    //lift down and stop
  }
  task::sleep(ttime);
}

void intake( float spinspd ) {
  // _______.spin(directionType::fwd, spinspd, velocityUnits::pct);
  // _______.spin(directionType::rev, spinspd, velocityUnits::pct);
  task::sleep(ttime);
}

void stopintake() {
  // _______.stop(vex::brakeType::coast);
  // _______.stop(vex::brakeType::coast);
  task::sleep(ttime);
}
//*/