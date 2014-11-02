// timer.c
// A custom timing system

#include "timer.h"

#ifndef timersused
#define timersused 0
#endif

#warn "(timer.c) TODO: fix timer struct to use functions to calculate seconds"

static pTimer_t timerSet[timersused];

static long currentTime = 0;
static byte minutesPassed = 0; //actually half-minutes
static int extraMS = 0;
static byte timers = 0;
//TODO: add system timer 

int initTimer(pTimer_t timer) {
	if (timer->initialized)
		return -1;
	clearTimer(timer);
	timer->start = 0;
	timer->initialized = true;
	timer->running = false;

	timerSet[timers++] = *timer;
	// The right side should not be dereferenced, but robotC complains otherwise
	// timerSet is an array of pointers, not objects...?
	return 0;
}

void startTimer(pTimer_t timer) {
	timer->previousTime = timer->milliseconds;
	timer->running = true;
	timer->start = timeInMS();
}

void stopTimer(pTimer_t timer) {
	timer->running = false;
}

void clearTimer(pTimer_t timer) {
   timer->previousTime = 0;
   timer->milliseconds = 0;
   timer->start = currentTime;
}

void updateTimer(pTimer_t timer) {
	if (timer->running) {
		timer->milliseconds = timer->previousTime + (timeInMS() - timer->start);
	}
}

void updateAllTimers() {
	for (int i = 0; i < timers; i++)
		updateTimer(timerSet[i]);
		// I don't think the address operator should be required here,
		// but RobotC complains if it's absent
}

void monitorSysTimer() {
	currentTime = time1[T1];
	if (currentTime >= 30000) {
		minutesPassed++;
		extraMS += time1[T1] - 30000; //should be zero or negligible, but it's here just in case
		ClearTimer(T1);
		currentTime = time1[T1];
	}
}

void timeInit() {
	ClearTimer(T1);
}

//total milliseconds of runtime
long timeInMS() {
	return extraMS + currentTime + (minutesPassed * 30000);
}

//total centiseconds of runtime
long timeInCS() {
	return timeInMS() / 10;
}

//total deciseconds of runtime
int timeInDS() {
	return (int)(timeInMS() / 100);
}

//total seconds of runtime
int timeInS() {
	return (int)(timeInMS() / 1000);
}

//seconds of runtime, but in a float
float runtime() {
	return (float) timeInMS() / 1000;
}
