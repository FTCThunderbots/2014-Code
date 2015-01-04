#autofixWhitespace.py
#A script that will scan all files and fix the whitespace contained within them

import common

def main():
	modified = 0
	for filename in common.getFiles(common.fileIsC):
		indent = ''
		for line in open(filename, 'r+'):
			i = 0
			while line[i] in [' ', '\t']:
				i += 1
			line = indent + line[i:]
			if '{' in line:
				indent += '\t'
			if '}' in line:
				indent = indent[:-2]
		