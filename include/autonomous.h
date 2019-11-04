#include "autonomous-config.h"

void autonomous( void ) {
  #include "visionconfig.h"
    driveForward( 2 * 12 ); // drive forwards
    driveForward(-2 * 12 ); // drive backwards
}