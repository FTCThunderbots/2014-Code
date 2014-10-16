// timer.c
// A custom timing system

#include "timer.h"

//typedef char byte;
//typedef int bool;
//#define true 1
//#define false 0

static long currentTime = 0;
static Timer_t timerSetM[0];
static byte timers = 0;
static Timer_t * timerSet = timerSetM;

//in user file:
//Timer_t **usetimername = newTimer();
//startTimer(usertimername);

Timer_t ** newTimer() {
	Timer_t newMaster[timers + 1];
	int i;
	for (i = 0; i < timers-1; i++)
		newMaster[i] = timerSetM[i];
	Timer_t newTimer;
	newTimer.seconds = 0; //          }
	newTimer.miliseconds = 0;//       } Code specific to timer type
	newTimer.running = false;//       }
	newTimer.previousTime = 0;//      }
	newMaster[timers] = newTimer;
	timers++;
	timerSetM[timers] = newTimer;
	timerSet = timerSetM;
	return (timerSet + (timers-1));
}

void startTimer(Timer_t **timer) {
	*timer->previousTime = (**timer).miliseconds;
	*timer->running = true;
	*timer->start = currentTime;
}

void clearTimer(Timer_t **timer) {
	(**timer).previousTime = 0;
	(**timer).seconds = 0;
	(**timer).miliseconds = 0;
}

void stopTimer(Timer_t timer) {
	timer.running = false;
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
	return (float)currentTime / 1000;
}	
