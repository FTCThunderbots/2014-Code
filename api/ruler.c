// ruler.c
// A custom encoder measurement system
// Should be very useful

#include "ruler.h"

#ifdef rulersused
static Ruler_t *rulerSet[rulersused];
#else
static Ruler_t *rulerSet[rulersused];
#endif

static byte rulers = 0;

/*
typedef struct Ruler {
   long left1_startTicks;
   long left2_startTicks;
   long right1_startTicks;
   long right2_startTicks;
   
	long left1_ticks;
   long left2_ticks;
   long right1_ticks;
   long right2_ticks;
   
   long left_ticks;
   long right_ticks;
   long front_ticks;
   long back_ticks;
   
   long drive_ticks;
   long strafe_ticks;
   long rotate_ticks;
   long swing_ticks;
   
   float drive_inches;
   float strafe_inches;
   float rotate_degrees;
   float swing_degrees;
   
   bool initialized;
   bool running;   
} Ruler_t;
*/

int initRuler(pRuler_t ruler) {
	if (ruler->initialized)
		return -1;
	clearRuler(ruler);
	ruler->running = true;
	ruler->initialized = true;
	rulerSet[rulers++] = *ruler;
	// See comments about similar issue with timerSet[]
	return 0;
}

void startTimer(pTimer_t timer) {
	timer->previousTime = timer->milliseconds;
	timer->running = true;
	timer->start = timeInMS();
}

void stopTimer(pTimer_t timer) {
	timer->running = false;
}

void clearRuler(pRuler_t ruler) {
	// reset start values to current positions
   updateRuler(ruler);
}

void updateTimer(pTimer_t timer) {
	if (timer->running) {
		long milliseconds = timer->previousTime + (timeInMS() - timer->start);
		timer->milliseconds = milliseconds;
		timer->seconds = (int)(milliseconds / 1000);
		timer->deciseconds = (int)(milliseconds / 100);
		timer->centiseconds = milliseconds / 10;
	}
}

void updateAllTimers() {
	for (int i = 0; i < timers; i++)
		updateTimer(&timerSet[i]);
		// I don't think the address operator should be required here,
		// but RobotC complains if it's absent
}

void monitorSysTimer() {
	currentTime = time1[T1];
	if (currentTime >= 30000) {
		minutesPassed++;
		extraMS += time1[T1] - 30000; //should be zero or negligible, but it's here just in case
		ClearTimer(T1);
		currentTime = time1[T1];
	}
}

void timeInit() {
	ClearTimer(T1);
}

//total milliseconds of runtime
long timeInMS() {
	return extraMS + currentTime + (minutesPassed * 30000);
}

//total centiseconds of runtime
long timeInCS() {
	return timeInMS() / 10;
}

//total deciseconds of runtime
int timeInDS() {
	return (int)(timeInMS() / 100);
}

//total seconds of runtime
int timeInS() {
	return (int)(timeInMS() / 1000);
}

//seconds of runtime, but in a float
float runtime() {
	return (float) timeInMS() / 1000;
}
