# function_testing.py

from math import *

joyRange = [10,127,117]
mtrRange = [0,100,100]
motorRange = mtrRange


def main():
	samples = [-0,-10, -50, -68, -100, -127, -150]
	for i in samples:
		print(i, setMovementFromJoystick(i,0))

def arrAbsmax(n):
	l = 4 # len
	cummax = n[0]
	for i in n:
		cummax = max(cummax, abs(i))
	return cummax

def POLARITY(n):
	return abs(n) / n if not n == 0 else 1
	
def scaleTo(value, range, scale):
	pol = POLARITY(value)
	if abs(value) < range[0]:
		return 0
	if abs(value) > range[1]:
		return scale[1] * pol
	posInR = (abs(value) - range[0]) / range[2];
	return pol * (scale[0] + (posInR * scale[2]))
	
def setMovement(forward, clockwise):
	forward = scaleTo(forward, motorRange, motorRange)
	clockwise = scaleTo(clockwise, motorRange, motorRange)
	
	frontLeft = -forward - clockwise
	frontRight = forward - clockwise
	backLeft = -forward - clockwise
	backRight = forward - clockwise
	
	power = [frontLeft, frontRight, backLeft, backRight]
	max = arrAbsmax(power)
	
	if max > 100:
		scale = max / 100
		for i in range(4):
			power[i] /= scale
			
	for i in range(4):
		power[i] *= 1
		
	return power
	
def correctJoystick(joyval):
	return scaleTo(joyval, joyRange, motorRange)
	
def setMovementFromJoystick(forward, clockwise):
	forward = correctJoystick(forward)
	clockwise = correctJoystick(clockwise)
	
	return setMovement(forward, clockwise)

print(arrAbsmax([100,-100,100,-100]))

main()