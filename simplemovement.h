//simplemovement.h
//Contains wrappers for making movement.c functions easier.

//Need to be implemented
void drive(short power);
void driveIn(short dist, short power);
void driveCm(short dist, short power);
void strafe(short power);
void strafeIn(short dist, short power);
void strafeCm(short dist, short power);
void rotate(short power);
void rotateDeg(short degs, short power);
void rotateRad(short rads, short power);

//Other ideas:
void swingTurn(short power); //and with degrees/rads

//Low priority: (Daniel's ideas)
void turnSpiral(byte power, short distance, short deg) {}
void moveDiagonal(char vect/*which diagonal?*/, byte power, short distance/*We need to decide: cm or in?* {}

*/
