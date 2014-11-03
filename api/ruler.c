// ruler.c
// A custom encoder measurement system
// Should be very useful

#include "ruler.h"

#ifndef rulersused
#define rulersused 0
#endif

static pRuler_t rulerSet[rulersused];
static pRuler_t sysRuler;
static bool sysRulerExists;
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

	long left1_previousTicks;
	long left2_previousTicks;
	long right1_previousTicks;
	long right2_previousTicks;

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

int initSysRuler(pRuler_t ruler) {
	if (ruler->initialized)
		return -1;
	clearRuler(ruler);
	ruler->running = true;
	ruler->initialized = true;
	sysRuler = ruler;
	sysRulerExists = true;
	return 0;
}

void destroySysRuler() {
	sysRulerExists = false;
	// Anything else should be done in context
}

void startRuler(pRuler_t ruler) {
	ruler->left1_previousTicks = ruler->left1_ticks;
	ruler->left2_previousTicks = ruler->left2_ticks;
	ruler->right1_previousTicks = ruler->right1_ticks;
	ruler->right2_previousTicks = ruler->right2_ticks;

	ruler->left1_startTicks = getEncoder_left1();
	ruler->left2_startTicks = getEncoder_left2();
	ruler->right1_startTicks = getEncoder_right1();
	ruler->right2_startTicks = getEncoder_right2();

	ruler->running = true;
}

void stopRuler(pRuler_t ruler) {
	ruler->running = false;
}

void clearRuler(pRuler_t ruler) {
	ruler->left1_startTicks = getEncoder_left1();
	ruler->left2_startTicks = getEncoder_left2();
	ruler->right1_startTicks = getEncoder_right1();
	ruler->right2_startTicks = getEncoder_right2();

	ruler->left1_previousTicks = 0;
	ruler->left2_previousTicks = 0;
	ruler->right1_previousTicks = 0;
	ruler->right2_previousTicks = 0;

	ruler->left1_ticks = 0;
	ruler->left2_ticks = 0;
	ruler->right1_ticks = 0;
	ruler->right2_ticks = 0;
}

void updateRuler(pRuler_t ruler) {
	if (ruler->running) {
		ruler->left1_ticks = getEncoder_left1() - ruler->left1_startTicks + ruler->left1_previousTicks;
		ruler->left2_ticks = getEncoder_left2() - ruler->left2_previousTicks + ruler->left2_previousTicks;
		ruler->right1_ticks = getEncoder_right1() - ruler->right1_previousTicks + ruler->right1_previousTicks;
		ruler->right2_ticks = getEncoder_right2() - ruler->right2_previousTicks + ruler->right2_previousTicks;
	}
}

void updateAllRulers() {
	for (int i = 0; i < rulers; i++)
		updateRuler(&rulerSet[i]);
	if (sysRulerExists)
		updateRuler(sysRuler);
}

long getLeftTicks(Ruler_t ruler) {
	return (ruler.left1_ticks + ruler.left2_ticks) / 2;
}

long getRightTicks(Ruler_t ruler) {
	return (ruler.right1_ticks + ruler.right2_ticks) / 2;
}

long getFrontTicks(Ruler_t ruler) {
	return (ruler.left1_ticks + ruler.right1_ticks) / 2;
}

long getBackTicks(Ruler_t ruler) {
	return (ruler.left2_ticks + ruler.right2_ticks) / 2;
}

long getDriveTicks(Ruler_t ruler) {
	return (-getLeftTicks(ruler) + getRightTicks(ruler)) / 2;
}

long getStrafeTicks(Ruler_t ruler) {
	return (-getFrontTicks(ruler) + getBackTicks(ruler)) / 2;
}

long getRotateTicks(Ruler_t ruler) {
	return -(getLeftTicks(ruler) + getRightTicks(ruler) / 2;
}

long getSwingTicks(Ruler_t ruler) {
	return -(getLeftTicks(ruler) + getRightTicks(ruler);
	// Not dividing by two is intentional here, since one side should be zero.
}
// Current encoder positions: cannot be done because the raw encoder values will be messed up