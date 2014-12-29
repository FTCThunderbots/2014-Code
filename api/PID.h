//PID.h
//header file for PID.c
//This is where we code the PID.

#define PID_INCLUDEGUARD

#define BOUND(n, l, h) (((n)<(l)) ? (l) : ((n)>(h)) ? (h) : (n))

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

typedef struct {
    const float windup_guard = INTEGRAL_CAP;
    const float proportional_gain = Kp;
    const float integral_gain = Ki;
    const float derivative_gain = Kd;
    float prev_error;
    float int_error;
    float control;
} PID;

void moveFor(int ticks, int speed);
void swingFor(int ticks, int speed);

void pid_zeroize(PID* pid);
void pid_update(PID* pid, float curr_error, float dt);


#ifndef ENCODERS_INCLUDEGUARD
#include "encoders.c"
#endif
