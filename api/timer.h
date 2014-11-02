// timer.h
// Header file for timer.c

#define TIMER_INCLUDEGAURD

typedef struct Timer {
	long milliseconds;
	long start;
	long previousTime;
	
	bool initialized;
	bool running;
} Timer_t;

typedef Timer_t * pTimer_t;

void startTimer(pTimer_t timer);
void stopTimer(pTimer_t timer);
void resetTimer(pTimer_t timer);
void updateTimer(pTimer_t timer);
void updateAllTimers();
void monitorSysTimer();
void timeInit();
long timeInMS();
long timeInCS();
int timeInDS();
int timeInS();
float runtime();
