// timer.h
// Header file for timer.c

#include "api.c"

/*
typedef char byte;
typedef int bool;
#define true 1
#define false 0 */

typedef struct Timer {
	int seconds;
	int deciseconds;
	long centiseconds;
	long milliseconds;
	bool running;
	long start;
	long previousTime;
	bool initialized;
} Timer_t;

typedef Timer_t * pTimer;

void startTimer(Timer_t *timer);
void stopTimer(Timer_t *timer);
void clearTimer(Timer_t *timer);
void updateTimer(Timer_t *timer);
void updateAllTimers();
void monitorSysTimer();
void timeInit();
long timeInMS();
long timeInCS();
int timeInDS();
int timeInS();
float runtime();
