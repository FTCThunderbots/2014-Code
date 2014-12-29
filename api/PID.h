//PID.h
//header file for PID.c
//This is where we code the PID.

#define PID_INCLUDEGUARD

#define BOUND(n, l, h) (((n)<(l)) ? (l) : ((n)>(h)) ? (h) : (n))

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

typedef struct {
    float windup_guard;
    float proportional_gain;
    float integral_gain;
    float derivative_gain;
    float prev_error;
    float int_error;
    float control;
} PID;

void correctLinear(int speed); //the correction algorithm for linear movement (driving)
void correctRotate(int posSpeed); //the correction algorithm for rotation

#ifndef setting_twoMotors
void correctSwing(int speed); //corrects for swing, will only be necessary if there is a four wheel drive
#endif

void pid_zeroize(PID* pid);
void pid_update(PID* pid, float curr_error, float dt);


#ifndef ENCODERS_INCLUDEGUARD
#include "encoders.c"
#endif
