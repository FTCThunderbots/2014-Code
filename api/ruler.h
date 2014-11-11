// ruler.h
// Header file for ruler.c

#define RULER_INCLUDEGAURD

#ifndef ENCODERS_INCLUDEGAURD
#include "encoders.c"
#endif

typedef struct EncoderSet {
   long left1;
   long left2;
   long right1;
   long right2;
} EncoderSet_t;

typedef EncoderSet_t * pEncoderSet_t;

typedef struct Ruler {
   EncoderSet_t ticks
	EncoderSet_t start;
   EncoderSet_t previous;
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
