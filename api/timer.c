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

/*
typedef struct Timer {
   float seconds;
	long milliseconds;
	bool running;
	long start;
	long previousTime;
	bool initialized;
} Timer_t;
*/

int initTimer(Timer_t *timer) {
	if (timer->initialized)
		return -1;
	timer->seconds = 0;
	timer->milliseconds = 0;
	timer->running = false;
	timer->start = 0;
	timer->previousTime = 0;
	timer->initialized = true;
	timerSet[timers++] = timer;
	return 0;
}

void startTimer(Timer_t *timer) {
	timer->previousTime = timer->milliseconds;
	timer->running = true;
	timer->start = currentTime;
}

void stopTimer(Timer_t *timer) {
	timer->running = false;
}

void clearTimer(Timer_t *timer) {
	timer->previousTime = 0;
	timer->seconds = 0;
	timer->milliseconds = 0;
}

void updateTimer(Timer_t *timer) {
	if (timer->running) {
		timer->milliseconds = timer->previoustime + (currentTime - timer->startTime);
		timer->seconds = (float)timer->milliseconds / 1000;
	}
}

void updateAllTimers() {
	for (int i = 0; i < timers; i++)
		updateTimer(timerSet[i]);
}

float runtime() {
	return (float)currentTime/1000;
}	
