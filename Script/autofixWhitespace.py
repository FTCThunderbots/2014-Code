# autofixWhitespace.py
# A script that will scan all files and fix the whitespace contained within them
# Code works perfectly as of 01/04/15 13:52
# Checked by Daniel

import common

SINGLELOOPS = ("if", "while", "for", "else", "else if") # What needs to be tabbed
WS_CHARS = (' ', '\t') # The whitespace characters

def main():
	modified = 0 # A count of the modified files
	for filename in common.getFiles(common.fileIsC): # All of the C code
		indent = '' # Indent and singleindent start at nothing
		singleindent = ''
		corrected = [] # Holds the entire corrected file before write
		lineAboveIsBlank = False # Used for deletion of extra space
		singleIndentFlag = False # Checks if we are in a single indent
		keepSingleIndent = False # Keeps the singleindent on while we are going through 
		tabAdded = False # Used for managing recursive singleloop tabs
		tabs = 0 # Counter for Tabs
		startTabs = 0 # Marker for where single tab started
		singleTabs = 0 # Counter for singleTabs
		file = open(filename, 'r')
		for line in file:
			if '}' in line and isPreceded(line, '}'): # If this is the end of a block, reduce the indent
				indent = indent[:-1]
				tabs -= 1
				tabAdded = False
				if singleIndentFlag:
					keepSingleIndent = tabs - startTabs > 0 # If this is not the end of the root block in a
										# single indent area, leave the single indent on
			i = 0
			while line[i] in WS_CHARS:
				i += 1
			if not (lineAboveIsBlank and lineIsBlank(line)): # If not doublespacing
				if lineIsBlank(line):
					corrected.append(line[i:]) # Empty lines don't need tabs
				else:
					corrected.append(indent + singleindent + line[i:]) # Write the tabs
			if lineIsBlank(line):
				lineAboveIsBlank = True 
			else:
				lineAboveIsBlank = False
			if '{' in line:
				indent += '\t' # Found the start of a block, increase indent
				tabs += 1
				tabAdded = True
				if singleIndentFlag:
					keepSingleIndent = True # There is a block in a single indent
			if '}' in line and not isPreceded(line, '}'): # Found the end of a block, decrease indent
				indent = indent[:-1]
				tabs -= 1
				tabAdded = False
				if singleIndentFlag:
					keepSingleIndent =  tabs - startTabs > 0 # If this is not the end of the root block in a
										 # single indent area, leave the single indent on

			if singleTabs > 1 and not tabAdded: # Manage recursive single indents
				singleTabs -= 1
				singleindent = singleindent[:-1]
			if isSingleLoop(line) and '{' not in line: # If this is a one line SINGLELOOP
				singleindent += '\t'
				singleTabs += 1
				singleIndentFlag = True
				if singleTabs == 1:
					startTabs = tabs
			elif not keepSingleIndent: # If the SINGLELOOP did not contain a block
				singleIndentFlag = False
				singleTabs = 0	
				singleindent = '' # Single loop indent should decrease after that line 
		file.close()
		print(keepSingleIndent)
		file = open(filename, 'w')
		file.truncate() # Empty the file
		for line in corrected:
			file.write(line) # Write the newly corrected file from buffer
		file.close()
		modified += 1 # All of that only corrected one file
	print("%d files were corrected" % modified)
	
def isSingleLoop(line) :
	if ';' in line:
		return False
	for loop in SINGLELOOPS:
		if (loop + ' ') in line:
			return True
		if (loop + '\n') in line:
			return True
		if (loop + "(") in line:
			return True
	return False

def isPreceded(line, char):
	return False not in [line[i] in WS_CHARS for i in range(line.index(char))]
	
def lineIsBlank(line):
	return False not in [char in WS_CHARS or char == '\n' for char in line]

if __name__ == "__main__":
	main()
