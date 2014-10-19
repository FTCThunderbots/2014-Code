// timer.h
// Header file for timer.c

#include "api.h"

typedef char byte;
typedef int bool;
#define true 1
#define false 0

typedef struct Timer {
   int seconds : 16;
   int deciseconds : 16;
   long centiseconds : 21;
   long milliseconds : 21;
   bool running : 1;
   long start : 20;
   long previousTime : 21;
   bool initialized : 1;
} Timer_t;

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
