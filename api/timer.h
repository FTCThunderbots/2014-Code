// timer.h
// Header file for timer.c

#include "api.h"

//declare Timer_t struct here
Timer_t * newTimer();
void startTimer(Timer_t timer);
void stopTimer(Timer_t timer);
void clearTimer(Timer_t timer);
task timing();

float runtime();