# linesWritten.py
# Returns how many lines of code exist in it's path.

'''
A replacement for this program is:
wc -l $(git ls-files)
'''

import os

EXCLUDED_FOLDERS = (".git", "api\Xander_Drivers")
EXCLUDED_FILES = ("","Batteries\\Battery Log 12-13-14.xlsx")
ACCEPTED_EXTENSIONS = ('.c', '.h', '.py')

def main():
	lines = 0
	for filename in getFiles():
		lines += lengthOf(filename)
	print("All the specified files contain a total of %d lines of code" % lines)

def lengthOf(filename):
	try:
		return sum(1 for line in open(filename))
	except:
		print("There was an error and %s could not be read" % filename)
		return 0

def getFiles():
	for dirname, dirnames, filenames in os.walk('..'):
		if not dirnameIsBanned(dirname):
			for file in filenames:
				if not filenameIsBanned(file, dirname):
					if isValidCode(file):
						yield os.path.join(dirname, file)
					
def dirnameIsBanned(dirname):
	dirname = dirname.lower()
	return (True in ["".join(("\\",exFolder,"\\")).lower() in dirname or dirname.endswith("".join(("\\",exFolder)).lower()) for exFolder in EXCLUDED_FOLDERS])
	
def filenameIsBanned(filename, dirname):
	return (True in [os.path.join(dirname, filename) == os.path.join("..",exFile) for exFile in EXCLUDED_FILES])
	
def isValidCode(file):
	return True in [file.endswith(ex) for ex in ACCEPTED_EXTENSIONS]
	
main()