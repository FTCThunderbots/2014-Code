#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     sweep,         tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    backboard,            tServoStandard)

#define setting_twoEncoders

/* How to set up the robot based on this configurations:


                        FRONT

(mtr_S1_C1_1) |  |-----------------|  | (mtr_S1_C2_1)
leftmotor_1   |--|                 |--|  rightmotor_1
encoder here  |  |                 |  |  encoder here
                 |                 |
                 |                 |
                 |***           ***|
  mtr_s1_c1 -->  |***           ***|  <-- mtr_s1_c2
                 |                 |
                 |                 |
(mtr_S1_C1_2) |  |                 |  | (mtr_S1_C2_2)
leftmotor_2   |--|                 |--|  rightmotor_2
              |  |-----------------|  |

                        BACK

*/


// main teleop.c
// Main tele-op program

#include "../api/api.c"

const byte SWEEP_MOTOR_POWER = 100;
const byte CONVEY_MOTOR_POWER = 100;

void setSweep();
void setConvey();

task main() {
	initializeAPI();
	while (true) {
		getJoystickSettings(joystick);
		setMovementFromJoystick(-joystick.joy1_y1, -joystick.joy1_x2);
    setSweep();
    setConvey();
	}
}

void setSweep() {
   byte pow = SWEEP_MOTOR_POWER;
   if (joy2Btn(0) || joy2Btn(3))
      pow /= 2;
   if (joy2Btn(6))
      motor[sweep] = pow;
   if (joy2Btn(4))
      motor[sweep] = -pow;
}

void setConvey() {
   byte pow = CONVEY_MOTOR_POWER;
   if (joy2Btn(2) || joy2Btn(3))
      pow /= 2;
   if (joy2Btn(7))
      motor[conveyor] = pow;
   if (joy2Btn(5))
      motor[conveyor] = -pow;
}
