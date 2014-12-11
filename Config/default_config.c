#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     grab,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backboard,     tmotorTetrix, openLoop)

#define setting_twoEncoders

//**THIS CONFIGURATION IS CURRENT AS OF 12/11/2014**

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
