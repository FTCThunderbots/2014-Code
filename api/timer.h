// timer.h
// Header file for timer.c

//macros
#define TIMER_INCLUDEGAURD

//function macros
#define waitSecs(timer, secs) while(getSeconds(timer)<secs){}

typedef struct TimeVal {
   long msecs; //milliseconds
   // could potentially change this to an int, after testing is done
   byte mins; //really half-minutes
} TimeVal_t;

typedef TimeVal_t * pTimeVal_t;

typedef struct Timer {
	TimeVal_t time;
	TimeVal_t begin;
	TimeVal_t previous;
	bool initialized;
	bool running;
} Timer_t;

typedef Timer_t * pTimer_t;

void startTimer(pTimer_t timer);
void stopTimer(pTimer_t timer);
void resetTimer(pTimer_t timer);
void toggleTimer(pTimer_t timer);
void updateTimer(pTimer_t timer);
void updateAllTimers();
void monitorSysTimer();
void timeInit();

long getMilliseconds(pTimer_t timer);
long getCentiseconds(pTimer_t timer);
int getDeciseconds(pTimer_t timer);
int getSeconds(pTimer_t timer);
float getRuntime(pTimer_t timer);

long timeInMS();
long timeInCS();
int timeInDS();
int timeInS();
float runtime();

long getTotalMilliseconds(pTimeVal_t time);
