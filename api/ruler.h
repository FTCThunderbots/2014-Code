// ruler.h
// Header file for ruler.c

#define RULER_INCLUDEGAURD

#ifndef ENCODERS_INCLUDEGAURD
#include "encoders.c"
#endif

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

typedef Ruler_t * pRuler_t;

int initRuler(pRuler_t ruler);
int initSysRuler(pRuler_t ruler);
void destroySysRuler();
void startRuler(pRuler_t ruler);
void stopRuler(pRuler_t ruler);
void clearRuler(pRuler_t ruler);
void updateRuler(pRuler_t ruler);
void updateAllRulers();
