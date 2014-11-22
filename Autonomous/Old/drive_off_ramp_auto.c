// drive off ramp auto.c
// The robot will start on top of the corner ramp, and drive forward
// for 2.5 seconds, onto the floor

#define setting_twoEncoders
#include "../api/api.c"

#warn "Time based autonomous!"
#error "NO PRAGMA!!!"

task main()
{
	initializeAPI();
	waitForStart();
	drive(100);
	wait1Msec(3000);
	drive(0);
	clampTube(FRONT);
}

void clamp
