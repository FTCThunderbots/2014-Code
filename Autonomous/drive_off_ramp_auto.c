// drive off ramp auto.c
// The robot will start on top of the corner ramp, and drive forward
// for 2.5 seconds, onto the floor

#define timersused 1
#include "../api/api.c"

task main()
{
	initializeAPI();
	waitForStart();
	Timer_t timer;
	pTimer_t pTimer;
	initTimer(pTimer);
	startTimer(pTimer);
	drive(100);
	while (getDeciseconds(pTimer) < 25) {}
	drive(0);
}
