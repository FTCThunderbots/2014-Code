#define COMPASS_INCLUDEGAURD

#include "compass_sensor.h"
#include "coord.h"

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
    int startD = getCompassReading();
    int checkDifference = degrees * sgn(power);

    rotateWithOrientation(degrees, power);

    int end = getCompassReading();

    if ((startD + checkDifference) % 360 <= abs(end + 5) % 360 || (startD + checkDifference) % 360 >= abs(end - 5) % 360) {
        return;                                     // Jumps back to previous code if successful, retries if not.
    } else {
        int degOff = abs((startD + checkDifference) - end);
        int sgnPower = sgn((startD + checkDifference) - end);
        rotateDegreesImp(degOff, power * sgnPower);            // Recursive calling until value is achieved.
        return;
    }
}

void swingDegreesImp(int degrees, byte direction, byte power) {
    int startD = getCompassReading();
    int checkDifference = degrees * sgn(power) * sgn(direction);

    swingWithCoords(degrees, direction, power);

    int end = getCompassReading();

    if ((startD + checkDifference) % 360 <= end + 5 || (startD + checkDifference) % 360 >= end - 5) {
        return;
    } else {
        int degOff = abs((startD + checkDifference) - getCompassReading());
        int sgnPower = sgn((startD + checkDifference) - getCompassReading());
        swingDegreesImp(degOff, direction * sgnPower, power);
        return;
    }
}

void setInitial() {
    initialCompassReading = SensorValue[compass];
}
