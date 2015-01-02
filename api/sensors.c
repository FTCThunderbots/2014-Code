// sensors.c
// Contains methods for getting the values of sensors on the robot

#include "sensors.h"

int initialCompassReading = 0;

int getCompassReading() {
    return SensorValue[compass];
}

int calculateAverageReading(int samples) {
    int reading = getCompassReading();

    for (int i = 0; i < samples; i++) {
        reading += getCompassReading();
    }

    return round(reading / samples);
}

void alignToCompassZero() {
    while (getCompassReading() != 0) {
        rotateWithOrientation(1, 25);
    }
}

void alignToInitial() {
    while (getCompassReading() != initialCompassReading) {
        rotateWithOrientation(1, 25);
    }
}

void rotateDegreesImp(int degrees, byte power) {    // "Imp" stands for 'improved'
    int start = getCompassReading();
    int checkDifference = degrees * sgn(power);

    rotateWithOrientation(degrees, power);

    int end = getCompassReading();

    if ((start + checkDifference) == end) {
        return;                                     // Jumps back to previous code if successful, retries if not.
    } else {
        int degOff = abs((start + checkDifference) - end);
        int sgnPower = sgn((start + checkDifference) - end);
        rotateDegreesImp(degOff, power * sgnPower);            // Recursive calling until value is achieved.
        return;
    }
}

void swingDegreesImp(int degrees, byte direction, byte power) {
    int start = getCompassReading();
    int checkDifference = degrees * sgn(power) * sgn(direction);

    swingWithCoords(degrees, direction, power);

    if ((start + checkDifference) == getCompassReading()) {
        return;
    } else {
        int degOff = abs((start + checkDifference) - getCompassReading());
        int sgnPower = sgn((start + checkDifference) - getCompassReading());
        swingDegreesImp(degOff, direction * sgnPower, power);
        return;
    }
}

void setInitial() {
    initialCompassReading = SensorValue(compass);
}
