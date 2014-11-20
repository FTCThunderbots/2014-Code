#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)

#define setting_twoEncoders

#include "../api/api.c"

// This program will drive off the ramp, pick up a goal, and carry it to the parking zone

task main() {
   initializeAPI();
   waitForStart();
   setMovementFromJoystick_old(-50, 0);
   nMotorEncoder[leftmotor_1] = 0;
   while (nMotorEncoder[leftmotor_1] > 1440*(96/(4*PI))) {setMovementFromJoystick_old(-50, 0); wait1Msec(10); nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
   setMovementFromJoystick_old(0, 0);
   wait1Msec(3000);
   setMovementFromJoystick_old(0, -50);
   nMotorEncoder[leftmotor_1] = 0;
   while (nMotorEncoder[leftmotor_1] > (8.5*(PI/2)/(4*PI))) {setMovementFromJoystick_old(0, -50); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
   setMovementFromJoystick_old(0, 0);
   wait1Msec(3000);
   setMovementFromJoystick_old(-50, 0);
   nMotorEncoder[leftmotor_1] = 0;
   while (nMotorEncoder[leftmotor_1] > -1440*24/(4*PI)) {setMovementFromJoystick_old(-50, 0); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
   setMovementFromJoystick_old(0, 0);
   wait1Msec(3000);
   setMovementFromJoystick_old(0, 50);
   nMotorEncoder[leftmotor_1] = 0;
   while (nMotorEncoder[rightmotor_1] > -8.5*(PI/2)/(4*PI)) {setMovementFromJoystick_old(0, 50); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
   setMovementFromJoystick_old(0, 0);
   wait1Msec(3000);
   setMovementFromJoystick_old(-50, 0);
   nMotorEncoder[leftmotor_1] = 0;
   while (nMotorEncoder[leftmotor_1] > -1440*12/(4*PI)) {setMovementFromJoystick_old(-50, 0); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
   setMovementFromJoystick_old(0, 0);
   setMovementFromJoystick_old(50, 0);
   nMotorEncoder[leftmotor_1] = 0;
   while (nMotorEncoder[leftmotor_1] > -1440*120/(4*PI)) {setMovementFromJoystick_old(50, 0); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
   setMovementFromJoystick_old(0, 0);
   /*driveInches(12*10); // 10 feet = 12*10 inches
   rotateDeg(180); // could equally be -180*/

   /*** Pick up the goal right here ***/

   /*driveInches(12*4); //just guessing here
   rotateDeg(30);
   driveInches(12*4); //still guessing*/
}
