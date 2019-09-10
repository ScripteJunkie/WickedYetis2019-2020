// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

vex::motor motor_L1 (vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor motor_R1 (vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::controller controlmain = vex::controller();