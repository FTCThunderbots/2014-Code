#autofixWhitespace.py
#A script that will scan all files and fix the whitespace contained within them

import common

common.EXCLUDED_FILES = ("api/pid.c", "Autonomous/ramp_goal_park_v3.c",
		"Testing/experimentalAutoDoNotUse.c", "Script/experimental/test.c")

SINGLELOOPS = ("if", "while", "for", "else", "else if")
WS_CHARS = (' ', '\t')

def main():
	modified = 0
	for filename in common.getFiles(common.fileIsC):
		indent = ''
		singleindent = ''
		corrected = []
		lineAboveIsBlank = False
		file = open(filename, 'r')
		for line in file:
			if '}' in line and isPreceded(line, '}'):
				indent = indent[:-1]
			i = 0
			while i < len(line) and line[i] in WS_CHARS:
				i += 1
			if not (lineAboveIsBlank and lineIsBlank(line)):
				corrected.append(indent + singleindent + line[i:])
			if lineIsBlank(line):
				lineAboveIsBlank = True
			else:
				lineAboveIsBlank = False
			if '{' in line:
				indent += '\t'
			if '}' in line and not isPreceded(line, '}'):
				indent = indent[:-1]
			if isSingleLoop(line) and '{' not in line:
				singleindent += '\t'
			else:
				singleindent = ''
		file.close()
		file = open(filename, 'w')
		file.truncate()
		for line in corrected:
			file.write(line)
		file.close()
		modified += 1
	print("%d files were corrected" % modified)
	
def isSingleLoop(line):
	for loop in SINGLELOOPS:
		if ('\t' + loop + ' ') in line:
			return True
		if ('\t' + loop + '\n') in line:
			return True
		if ('} ' + loop + ' ') in line:
			return True

def isPreceded(line, char):
	return False not in [line[i] in WS_CHARS for i in range(line.index(char))]
	
def lineIsBlank(line):
	return False not in [char in WS_CHARS or char == '\n' for char in line]

main()