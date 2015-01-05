#common.py
# A collection of common functions that are used by more than one script

import os

EXCLUDED_FOLDERS = (".git", "api\Xander_Drivers", "Batteries", "Notebook")
EXCLUDED_FILES = []
ACCEPTED_EXTENSIONS = ('.c', '.h', '.py')

#A generator that returns all the files in the repo matching a given set of conditions
def getFiles(condition):
   for dirname, dirnames, filenames in os.walk(os.path.join('..', '..')):
      if not dirnameIsBanned(dirname):
         for file in filenames:
            if not filenameIsBanned(file, dirname):
               if condition(file):
                  yield os.path.join(dirname, file)
						
					#if file.endswith(".c"):
						#yield os.path.join(dirname, file)
						
def dirnameIsBanned(dirname):
   dirname = dirname.lower()
   return (True in [("\\"+exFolder+"\\").lower() in dirname or dirname.endswith(("\\"+exFolder).lower()) for exFolder in EXCLUDED_FOLDERS])
	
def filenameIsBanned(filename, dirname):
   filename = filename.lower()
   dirname = dirname.lower()
   return (True in [os.path.join(dirname, filename) == os.path.join("..",exFile).lower() for exFile in EXCLUDED_FILES])
	
def isValidCode(file):
   return True in [file.endswith(ex) for ex in ACCEPTED_EXTENSIONS]
   
def fileIsC(file):
	return file.endswith(".c") or file.endswith(".h")
	
def countInstances(line, char):
	sum = 0
	for i in range(len(line)):
		if line[i] == char:
			sum += 1
	return sum