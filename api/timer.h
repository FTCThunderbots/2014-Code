// timer.h
// all of the delaying functions

//macros
#define TIMER_INCLUDEGUARD

//function macros
#define waitMilliseconds(Msecs) wait1Msec(Msecs)
#define waitCentiseconds(Csecs) wait1Msec(Csecs*10)
#define waitDeciseconds(Dsecs) wait1Msec(Dsecs*100)
#define delay(secs) wait10Msec(secs*100)
