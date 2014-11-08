// timer.c
// A sophisticated custom timing system

#include "timer.h"

#ifndef timersused
#define timersused 1
#endif

static pTimer_t timerSet[timersused];

static long currentTime = 0;
static byte minutesPassed = 0; //actually half-minutes
static int extraMS = 0;
static byte timers = 0;

int initTimer(pTimer_t timer) {
	if (timer->initialized)
		return -1;
	resetTimer(timer);
	timer->begin = 0;
	timer->initialized = true;
	timer->running = false;

	timerSet[timers++] = timer;
	return 0;
}

void startTimer(pTimer_t timer) {
	timer->previousTime = timer->milliseconds;
	timer->running = true;
	timer->begin = timeInMS();
}

void stopTimer(pTimer_t timer) {
	timer->running = false;
}

void resetTimer(pTimer_t timer) {
   timer->previousTime = 0;
   timer->milliseconds = 0;
   timer->begin = currentTime;
 }

void updateTimer(pTimer_t timer) {
	if (timer->running) {
		timer->milliseconds = timer->previousTime + (timeInMS() - timer->begin);
	}
}

void updateAllTimers() {
	for (int i = 0; i < timers; i++)
		updateTimer(timerSet[i]);
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

// Accessing timer values

long getMilliseconds(pTimer_t timer) {
	return timer->milliseconds;
}

long getCentiseconds(pTimer_t timer) {
	return timer->milliseconds / 10;
}

int getDeciseconds(pTimer_t timer) {
	return timer->milliseconds / 100;
}

int getSeconds(pTimer_t timer) {
	return timer->milliseconds / 1000;
}

float getRuntime(pTimer_t timer) {
	return (float)timer->milliseconds / 1000;
}

// Total runtime

// milliseconds
long timeInMS() {
	return extraMS + currentTime + (minutesPassed * 30000);
}

//centiseconds
long timeInCS() {
	return timeInMS() / 10;
}

//deciseconds
int timeInDS() {
	return (int)(timeInMS() / 100);
}

//seconds
int timeInS() {
	return (int)(timeInMS() / 1000);
}

//seconds, but in a float
float runtime() {
	return (float) timeInMS() / 1000;
}
