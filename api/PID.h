//PID.h
//header file for PID.c
//This is where we code the PID.

#define PID_INCLUDEGUARD

#define BOUND(n, l, h) (((n)<(l)) ? (l) : ((n)>(h)) ? (h) : (n))

typedef struct {
    double windup_guard;
    double proportional_gain;
    double integral_gain;
    double derivative_gain;
    double prev_error;
    double int_error;
    double control;
} PID;

void correctLinear(int speed); //the correction algorithm for linear movement (driving)
void correctRotate(int posSpeed); //the correction algorithm for rotation

#ifndef setting_twoMotors
void correctSwing(int speed); //corrects for swing, will only be necessary if there is a four wheel drive
#endif

void pid_zeroize(PID* pid);
void pid_update(PID* pid, double curr_error, double dt);
