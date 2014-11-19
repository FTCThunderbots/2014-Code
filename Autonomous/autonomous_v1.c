#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)

#define setting_twoEncoders

#include "../api/api.c"
#include "../testing/coord_test.c"

// This program will drive off the ramp, pick up a goal, and carry it to the parking zone
float x = 0.0;
float z = 0.0;
float orientation = 0.0;
int degrees = 90;

task main() {
   initializeAPI();
   waitForStart();
   setMovementFromJoystick_old(-50, 0);
   while (nMotorEncoder[leftmotor_1] < 1440*96) {setMovementFromJoystick_old(-50, 0); wait1Msec(10);}
   setMovementFromJoystick_old(0, 0);
   wait1Msec(3000);
   setMovementFromJoystick_old(0, -50);
   while (nMotorEncoder[leftmotor_1] < 8.5*(PI/2)) {setMovementFromJoystick_old(0, -50); wait1Msec(10);}
   setMovementFromJoystick_old(0, 0);
   wait1Msec(3000);
   setMovementFromJoystick_old(-50, 0);
   while (nMotorEncoder[leftmotor_1] < 1440*24) {setMovementFromJoystick_old(-50, 0); wait1Msec(10);}
   setMovementFromJoystick_old(0, 0);
   wait1Msec(3000);
   setMovementFromJoystick_old(0, 50);
   while (nMotorEncoder[rightmotor_1] < 8.5*(PI/2)) {setMovementFromJoystick_old(0, 50); wait1Msec(10);}
   setMovementFromJoystick_old(0, 0);
   wait1Msec(3000);
   setMovementFromJoystick_old(-50, 0);
   while (nMotorEncoder[leftmotor_1] < 1440*12) {setMovementFromJoystick_old(-50, 0); wait1Msec(10);}
   setMovementFromJoystick_old(0, 0);
   setMovementFromJoystick_old(50, 0);
   while (nMotorEncoder[leftmotor_1] < 1440*120) {setMovementFromJoystick_old(50, 0); wait1Msec(10);}
   setMovementFromJoystick_old(0, 0);

   driveInches(12*10); // 10 feet = 12*10 inches

   x += updateX(10.0, degrees);
   z += updateZ(10.0, degrees);

   rotateDeg(180); // could equally be -180

   degrees += 180;

   orientation = getOrientation(degrees);

   /*** Pick up the goal right here ***/

   driveInches(12*4); //just guessing here

   x += updateX(4.0, degreesToRadians(degrees));
   z += updateZ(4.0, degreesToRadians(degrees));

   rotateDeg(30);

   degrees += 30;
   orientation = getOrientation(degreesToRadians(degrees));

   driveInches(12*4); //still guessing

   x += updateX(4.0, degreesToRadians(degrees));
   z += updateZ(4.0, degreesToRadians(degrees));
}
