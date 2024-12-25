#include "vex.h"
using namespace vex;

int hangControlTask()
{
    while (true)
    {
        if (Controller1.ButtonL1.pressing())
        {
            hang1.setMaxTorque(100, percent);
            hang1.spin(reverse, 10, volt);
        }
        else if (Controller1.ButtonA.pressing())
        {
            hang1.spin(forward, 6, volt);
            
        }
        else if (Controller1.ButtonX.pressing())
        {

            hang1.setMaxTorque(100, percent);
            hang1.spinToPosition(-57, degrees, 80, rpm, true);
            Controller1.rumble("...");
        }
        else if (Controller1.ButtonB.pressing())
        {
            if (hang1.position(degrees) > -50)
            {
                hang1.spinToPosition(-50, degrees, 35, rpm, true);
            }
            else
            {
                hang1.stop(hold);
            }
        }
        else
        {
            hang1.setMaxTorque(100, percent);
            hang1.stop(hold);
        }
        wait(20, msec);
    }
    return 0;
}