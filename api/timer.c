// timer.c
// A custom timing system

#include "timer.h"

#ifdef timersused
static Timer_t * timerSet[timersused];
#else
static Timer_t * timerSet[0];
#endif

static long currentTime = 0;
static byte timers = 0;

/* in user file:
 * Timer_t usertimername;
 * initTimer(usertimername);
 * ...
 * startTimer(usertimername);
 */

void initTimer(Timer_t *timer)

void startTimer(Timer_t *pTimer) {
	pTimer->previousTime = pTimer->miliseconds;
	pTimer->running = true;
	pTimer->start = currentTime;
}

void clearTimer(Timer_t *pTimer) {
	pTimer->previousTime = 0;
	pTimer->seconds = 0;
	pTimer->miliseconds = 0;
}

void stopTimer(Timer_t *pTimer) {
	pTimer->running = false;
}	

//task timing() {
	//update timer stuff in here:
	
	/* General structure:
	 * Keep one native RobotC timer running at all times, counting milliseconds
	 * In each iteration, for all elements in timerSet[]:
	 * 		If running, update seconds and miliseconds fields
	 */
//}

float runtime() {
	return (float)(currentTime/1000);
}	
