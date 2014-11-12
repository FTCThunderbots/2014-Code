// timer.c
// A sophisticated custom timing system

#include "timer.h"

#ifndef timersused
#define timersused 1
#endif

static pTimer_t timerSet[timersused];
static TimeVal_t currentTime;
static byte timers = 0;

int initTimer(pTimer_t timer) {
	if (timer->initialized)
		return -1;
	resetTimer(timer);
	timer->begin.msecs = 0;
	timer->begin.mins = 0;

	timer->initialized = true;
	timer->running = false;

	timerSet[timers++] = timer;
	return 0;
}

void startTimer(pTimer_t timer) {
	timer->previous = timer->time;
	timer->running = true;
	timer->begin = currentTime;
}

void stopTimer(pTimer_t timer) {
	timer->running = false;
}

void resetTimer(pTimer_t timer) {
   timer->previous.msecs = 0;
   timer->previous.mins = 0;
   timer->time.msecs = 0;
   timer->time.mins = 0;
   timer->begin.mins = currentTime.mins;
   timer->begin.msecs = currentTime.msecs;
 }

// toggle the running state of the timer
void toggleTimer(pTimer_t timer) {
	if (timer->running)
		stopTimer(timer);
	else
		startTimer(timer);
}

void updateTimer(pTimer_t timer) {
	if (timer->running) {
    timer->time.mins = currentTime.mins - timer->begin.mins + timer->previous.mins;
		long totalMsec = (long)currentTime.msecs - (long)(timer->begin.msecs) + (long)(timer->previous.msecs); //leave the casts for now
		timer->time.msecs = totalMsec % 30000; // may change divisor?
		timer->time.mins += totalMsec / 30000;
	}
}

void updateAllTimers() {
	for (int i = 0; i < timers; i++)
		updateTimer(timerSet[i]);
}

void monitorSysTimer() {
	currentTime.msecs = time1[T1];
	if (time1[T1] >= 30000) {
		ClearTimer(T1);
		currentTime.mins += 1;
	}
}

void timeInit() {
	ClearTimer(T1);
	currentTime.msecs = 0;
	currentTime.mins = 0; //actually half-minutes
}

// Accessing timer values
// TODO: replace these with macros?

long getMilliseconds(pTimer_t timer) {
	return getTotalMilliseconds(&(timer->time));
}

long getCentiseconds(pTimer_t timer) {
	return getTotalMilliseconds(&timer->time) / 10;
}

int getDeciseconds(pTimer_t timer) {
	return getTotalMilliseconds(&timer->time) / 100;
}

int getSeconds(pTimer_t timer) {
	return getTotalMilliseconds(&(timer->time)) / 1000;
}

float getRuntime(pTimer_t timer) {
	return (float)getTotalMilliseconds(&(timer->time)) / 1000;
}

// Total runtime

// milliseconds
long timeInMS() {
	return getTotalMilliseconds(&currentTime);
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

long getTotalMilliseconds(pTimeVal_t time) {
	return (30000 * (long)time->mins) + time->msecs;
}