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

void moveFor(int ticks, int speed, bool PID);
void swingFor(int ticks, int direction, int speed, bool PID);

void pid_zeroize(PID* pid);
void pid_update(PID* pid, float curr_error, float dt);


#ifndef ENCODERS_INCLUDEGUARD
#include "encoders.c"
#endif
