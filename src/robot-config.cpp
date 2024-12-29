#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
motor L1 = motor(PORT1, ratio6_1, false);
motor L2 = motor(PORT4, ratio6_1, true);
motor L3 = motor(PORT3, ratio6_1, true);
motor R1 = motor(PORT6, ratio6_1, true);
motor R2 = motor(PORT9, ratio6_1, false);
motor R3 = motor(PORT10, ratio6_1, false);
inertial Inertial = inertial(PORT5);
controller Controller1 = controller(primary);
motor intake = motor(PORT14, ratio6_1, true);
optical Optical = optical(PORT7);
optical Optical_go = optical(PORT12);
motor intakedown = motor(PORT11, ratio18_1, false);
digital_out pushCylinder = digital_out(Brain.ThreeWirePort.A);
digital_out intakeCylander = digital_out(Brain.ThreeWirePort.B);
digital_out redlight = digital_out(Brain.ThreeWirePort.C);
digital_out whitelight = digital_out(Brain.ThreeWirePort.D);
digital_out hookCylinder = digital_out(Brain.ThreeWirePort.G);
motor hang1 = motor(PORT19, ratio36_1, true);
vex::vision Vision1 = vex::vision(vex::PORT13, 50);
vex::vision Vision2 = vex::vision(vex::PORT15, 50);

// 88
//  VEXcode generated functions
//  define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void)
{
  // nothing to initialize
}