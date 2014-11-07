# linesWritten.py
# Returns how many lines of code exist in it's path.

# Please keep this list alphebetized

def lengthOf(filename):
	try:
		return sum(1 for line in open('../' + filename))
	except:
		print("There was an error and %s could not be read" % filename)
		return 0;

# Main code

lines = 0
for filename in open('../List of files.txt'):
	if len(filename) > 2:
		file = filename[:-1]
		lines += lengthOf(file)
	
print("All the specified files contain a total of %d lines of code" % lines)