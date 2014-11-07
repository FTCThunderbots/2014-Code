// sensors.c
// Contains methods for getting the values of sensors on the robot

#include "sensors.h"

int getCompassValue() {
	if (compass_name)
		return SensorValue[compass_name];
	else
		return -1;
}
