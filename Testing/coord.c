#include "coord.h"

#define COORD_INCLUDEGAURD

#define PI      3.1415926535823

float x, z, orientation;

void setDefaults() {
	x = 0.0;
	z = 0.0;
	orientation = 0.0;
}

void updateDirection(float degrees) {
	orientation = (180/PI)*orientation;
	orientation = ((orientation + degrees) % 360.0) - PI;
	orientation = degreesToRadians(orientation);
}

void updateCoords(float distance) {
	x += distance * sin(orientation);
	z += distance * cos(orientation);
}

void gotoCoords(float newX, float newZ, float newO) {
    /*
        This is a work-in-progress!!!!
        This will go to the specified coordinates and rotate to the specified angle, assuming the PID is working
        correctly. This is a very systematic function, only use when absolutely necessary!
    */
    while (readValues('o') != 90) {     // very low tolerance
        rotateWithOrientation(1, 25);   // very slow, and low rotation to insure accuracy
    }
    if (newX == x) {
        while (false) {}                // empty loop just for fun! :D
    }
    else if (newX < x) {
        while (readValues('x') > newX)
            moveWithDirection(1, -25);   // Low and slow is the way to go!
    }
    else if (newX > x) {
        while (readValues('x') < newX)
            moveWithDirection(1, -25);
    }

    while (readValues('o') != 0) {
        rotateWithOrientation(1, 25);
    }

    if (newZ == z) {
        while (false) {}                // empty loop just for fun! :D
    }
    else if (newZ < z) {
        while (readValues('z') > newX)
            moveWithDirection(1, -25);   // Low and slow is the way to go!
    }
    else if (newZ > z) {
        while (readValues('z') < newX)
            moveWithDirection(1, -25);
    }

    while (readValues('o') != newO)
        rotateWithOrientation(1, 25);

    setCoords(newX, newZ, newO);
}

float readValues(char value) {
	if (value == 'x')
		return x;
	else if (value == 'z')
		return z;
	else
		return (orientation * 180 / PI);
}


void rotateWithOrientation(int degrees, byte power) {
    rotateDegrees(degrees, power);
    updateDirection(degrees * sgn(power));
}

void moveWithDirection(float distance, byte power) {
    driveInches(distance, power);
    updateCoords(distance * sgn(power));
}

void setCoords(float newX, float newZ, float newO) {
    x = newX;
    z = newZ;
    orientation = newO;
}
