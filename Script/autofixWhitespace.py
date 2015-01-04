#autofixWhitespace.py
#A script that will scan all files and fix the whitespace contained within them

import common

SINGLELOOPS = ("if", "while", "for", "else", "else if")

def main():
	modified = 0
	for filename in common.getFiles(common.fileIsC):
		indent = ''
		singleindent = ''
		corrected = []
		#try:
		file = open(filename, 'r')
		for line in file:
			if '}' in line and '{' not in line:
				indent = indent[:-1]
			i = 0
			while line[i] in [' ', '\t']:
				i += 1
			corrected.append(indent + singleindent + line[i:])
			if '{' in line:
				indent += '\t'
				if '}' in line:
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
		#except:
			#print("Error:", filename, "could not be edited")
	print("%d files were corrected" % modified)
	
def isSingleLoop(line) :
	for loop in SINGLELOOPS:
		if ('\t' + loop + ' ') in line:
			return True
		if ('\t' + loop + '\n') in line:
			return True


main()