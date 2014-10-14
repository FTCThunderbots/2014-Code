// timer.c
// A custom timing system

#include "timer.h"

static long currentTime = 0;
static TimerLinkedList_t timerSet;
timerSet.length = 0;

//in user file:
//Timer *usetimername = newTimer()

/*typedef struct TimerListNode {
   TimerListNode_t *next;
   
   float seconds;
	long miliseconds;
	bool running;
	long start;
	long previousTime;
} TimerListNode_t;

typedef struct TimerLinkedList {
   TimerListNode_t head;
   byte length;
} TimerLinkedList_t;*/

Timer_t * newTimer(void) {
	Timer_t newMasterTimerSet[timerSet.length + 1];
	for (byte i = 0; i < newTimerSet.length; i++)
		newTimerSet[i] = timerSet[i];
	Timer_t newTimer;
	newTimer.seconds = 0;
	newTimer.miliseconds = 0;
	newTimer.running = false;
	newTimer.previousTime = 0;
	newTimerSet[newTimerSet.length - 1] = newTimer;
	return &newTimerSet[newTimerSet.length - 1];
}

void startTimer(Timer_t timer) {
	timer.previousTime = timer.miliseconds;
	timer.running = true;
	timer.start = currentTime;
}

void clearTimer(Timer_t timer) {
	timer.previousTime = 0;
	timer.seconds = 0;
	timer.miliseconds = 0;
}

void stopTimer(Timer_t timer) {
	timer.running = false;
	

task timing() {
	//update timer stuff in here:
	
	/* General structure:
	 * Keep one native RobotC timer running at all times, counting milliseconds
	 * In each iteration, for all elements in timerSet[]:
	 * 		If running, update seconds and miliseconds fields
	 */
}

float runtime() {
	return (float)currentTime / 1000;
}	
