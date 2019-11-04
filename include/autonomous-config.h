#include "api.h"

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
    motor_R1.startRotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
    motor_L2.startRotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct
    );
    motor_R2.rotateFor(
        degrees * GEAR_RATIO, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
}

void turn( float degrees ) {
    // Note: +90 degrees is a right turn
    float turningRatio = TURNING_DIAMETER / WHEEL_DIAMETER;
    float wheelDegrees = turningRatio * degrees;    
    // Divide by two because each wheel provides half the rotation
    motor_L1.rotateFor(
        wheelDegrees * GEAR_RATIO / 2, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R1.rotateFor(
        wheelDegrees * GEAR_RATIO / 2, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_L2.rotateFor(
        wheelDegrees * GEAR_RATIO / 2, vex::rotationUnits::deg, 
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
    motor_R2.rotateFor(
        wheelDegrees * GEAR_RATIO / 2, vex::rotationUnits::deg,
        AUTON_DRIVE_PCT, vex::velocityUnits::pct, false
    );
} 

