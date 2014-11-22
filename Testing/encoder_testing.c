#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     infrared,        sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touch,          sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     rightmotor_1,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     leftmotor_2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     rightmotor_2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     lift1,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     lift2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    bucket,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    pin,                  tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)

#define setting_twoEncoders
/* USING THE 2013 CONFIG */

#define DEBUG_STREAM_ON
/*
long l1 = 0;
long l2 = 0;
long r1 = 0;
long r2 = 0;
*/
#define debugStreamLine1 getEncoder_left1()
#define debugStreamLine2 getEncoder_left2()
#define debugStreamLine3 getEncoder_right1()
#define debugStreamLine4 getEncoder_right2()

#include "../api/api.c"

task main() {
   driveSeconds(2, 100);
   while (true) {

   }
}
