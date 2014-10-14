// timer.h
// Header file for timer.c

#include "api.h"

//deprecated, should remove soon
typedef struct Timer {
	float seconds;
	long miliseconds;
	bool running;
	long start;
	long previousTime;// if the timer is stopped/started
} Timer_t;

typedef struct TimerListNode {
   TimerListNode_t *next;
   
   float seconds;
	long miliseconds;
	bool running;
	long start;
	long previousTime;
} TimerListNode_t;

typedef struct TimerLinkedList {
   TimerListNode_t head;
   byte length;
} TimerLinkedList_t;

Timer_t * newTimer();
void startTimer(Timer_t timer);
void stopTimer(Timer_t timer);
void clearTimer(Timer_t timer);
task timing();

float runtime();