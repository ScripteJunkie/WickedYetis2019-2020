/*vex-vision-config:begin*/
#include "v5.h"
#include "v5_vcs.h"
vex::vision::signature CUBEG = vex::vision::signature (1, -6657, -5297, -5977, -5409, -4297, -4853, 4.9, 0);
vex::vision::signature CUBEP = vex::vision::signature (2, 1821, 3159, 2490, 5163, 7919, 6541, 4.4, 0);
vex::vision::signature CUBEO = vex::vision::signature (3, 10001, 11657, 10829, -3399, -2797, -3098, 5.8, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision Vision1 = vex::vision (vex::PORT20, 50, CUBEG, CUBEP, CUBEO, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/