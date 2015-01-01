# autopushConfiguration.py
# Will get the default configuration, and replace every other
# found configuration with that default configuration
# (excluding the /config/ folder, for obvious reasons)

# There must be at least two items in each
EXCLUDED_FOLDERS = (".git", "old", "api", "config", "notebook")
EXCLUDED_FILES = ("","Batteries\\Battery Log 12-13-14.xlsx")

import os

    #for filename in filenames:
        #print(os.path.join(dirname, filename))
		
def main():
	defaultConfig = getDefaultConfig()
	#print(defaultConfig)
	fileList = getFiles()
	modified = 0
	for file in fileList:
		modified += replaceConfig(defaultConfig, file)
	print("%d files have been updated" % modified)
		
def getDefaultConfig():
	for line in open('../Config/default_config.c'):
		if line.startswith("#pragma "):
			yield line
	
def getFiles():
	for dirname, dirnames, filenames in os.walk('..'):
		if not dirnameIsBanned(dirname):
			for file in filenames:
				if not filenameIsBanned(file, dirname):
					if file.endswith(".c"):
						yield os.path.join(dirname, file)
						
def replaceConfig(defaultConfig, filename):
	fileobj = open(filename, 'r')
	file = [line for line in fileobj]
	if "//USE DEFAULT CONFIG\n" in file: #the file should be replaced with the default
		i = 0
		while file[i].startswith("#pragma "):
			i += 1
		nonConfigLines = file[i:]
		for l in nonConfigLines: print(l[:-1])
		fileobj.close()
		fileobj = open(filename, 'r+')
		fileobj.truncate()
		#print(len(fileobj))
		for line in defaultConfig:
			fileobj.write(line)
		for line in nonConfigLines:
			fileobj.write(line)
		fileobj.close()
		return 1
	else:
		fileobj.close()
		return 0
def dirnameIsBanned(dirname):
	dirname = dirname.lower()
	return (True in ["".join(("\\",exFolder,"\\")).lower() in dirname or dirname.endswith("".join(("\\",exFolder)).lower()) for exFolder in EXCLUDED_FOLDERS])
	
def filenameIsBanned(filename, dirname):
	return (True in [os.path.join(dirname, filename) == os.path.join("..",exFile) for exFile in EXCLUDED_FILES])
	
main()