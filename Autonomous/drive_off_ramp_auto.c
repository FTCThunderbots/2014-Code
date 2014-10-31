// drive off ramp auto.c
// The robot will start on top of the corner ramp, and drive forward
// for 2.5 seconds, onto the floor

#include "api.c"

task main()
{
	initializeAPI();
	waitForStart();
	drive(100);
	wait1Msec(2500);
	drive(0);
}
