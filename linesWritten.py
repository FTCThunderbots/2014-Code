# linesWritten.py
# Returns how many lines of code exist in it's path.

# Please keep this list alphebetized
filesToCheck = ('api/api.h',
	'api/config.c',
	'api/functions.c',
	'api/functions.h',
	'api/math.c',
	'api/math.h',
	'api/movement.c',
	'api/movement.h',
	'api/sensors.c',
	'api/sensors.h',
	'api/settings.c',
	'api/simplemovement.c',
	'api/simplemovement.h')

def lengthOf(filename):
	try:
		return sum(1 for line in open(filename))
	except:
		print("There was an error and " + filename + " could not be read")
		return 0;

# Main code

lines = 0
for file in filesToCheck:
	lines += lengthOf(file)
	
print("All the specified files contain a total of %d lines of code" % lines)