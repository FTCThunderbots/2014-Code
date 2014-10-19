// timer.h
// Header file for timer.c

#include "api.h"

typedef char byte;
typedef int bool;
#define true 1
#define false 0

typedef struct Timer {
   float seconds;
	long milliseconds;
	bool running;
	long start;
	long previousTime;
	bool initialized;
} Timer_t;

void startTimer(Timer_t *timer);
void stopTimer(Timer_t *timer);
void clearTimer(Timer_t *timer);
void updateTimer(Timer-t *timer);
void updateAllTimers();
float runtime();
