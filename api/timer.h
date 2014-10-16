// timer.h
// Header file for timer.c

//#include "api.h"

typedef char byte;
typedef int bool;
#define true 1
#define false 0

typedef struct Timer {
   float seconds;
	long miliseconds;
	bool running;
	long start;
	long previousTime;
} Timer_t;


Timer_t **newTimer();
void startTimer(Timer_t * pTimer);
void stopTimer(Timer_t * pTimer);
void clearTimer(Timer_t * pTimer);
//task timing();

float runtime();
