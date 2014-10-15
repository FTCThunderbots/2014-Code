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

/*
Timer_t **newTimer();
void startTimer(Timer_t timer);
void stopTimer(Timer_t timer);
void clearTimer(Timer_t timer);
//task timing();

float runtime();
*/