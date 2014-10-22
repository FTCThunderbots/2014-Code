// timer.c
// A custom timing system

#include "timer.h"

#ifdef timersused
static Timer_t *(timerSet[timersused]);
#else
static Timer_t *(timerSet[0]);
#endif

static long currentTime = 0;
static byte minutesPassed = 0;
static int extraMS = 0;
static byte timers = 0;

int initTimer(pTimer_t timer) {
	if (timer->initialized)
		return -1;
	clearTimer(timer);
	timer->running = false;
	timer->start = 0;
	timer->initialized = true;
	timerSet[timers++] = *timer;
	// The right side should not be dereferenced, but robotC complains otherwise
	// timerSet is an array of pointers, not objects...?,
	return 0;
}

void startTimer(pTimer_t timer) {
	timer->previousTime = timer->milliseconds;
	timer->running = true;
	timer->start = timeInMS();
}

void stopTimer(Timer_t *timer) {
	timer->running = false;
}

void clearTimer(pTimer_t timer) {
	timer->previousTime = 0;
	timer->seconds = 0;
	timer->deciseconds = 0;
	timer->centiseconds = 0;
	timer->milliseconds = 0;
}

void updateTimer(pTimer_t timer) {
	if (timer->running) {
		long milliseconds = timer->previousTime + (timeInMS() - timer->start);
		timer->milliseconds = milliseconds;
		timer->seconds = (int)(milliseconds / 1000);
		timer->deciseconds = (int)(milliseconds / 100);
		timer->centiseconds = milliseconds / 10;
	}
}

void updateAllTimers() {
	for (int i = 0; i < timers; i++)
		updateTimer(&timerSet[i]);
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
