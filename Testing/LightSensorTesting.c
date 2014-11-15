#pragma config(Sensor, S3,	lightSensor,			sensorLightActive)

bool useSensor = true;

task getLightSensorData()
{
		wait1Msec(10);
		while (useSensor) {
			if (SensorValue(lightSensor) > 50) {
					stop();
			}
		}

		stop();
}

void toggleSensor()
{
	useSensor = !useSensor;
}

task main()
{
	startTask(getLightSensorData);
	toggleSensor();
	toggleSensor();
	startTask(getLightSensorData);
	toggleSensor();
}
