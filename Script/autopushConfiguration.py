# autopushConfiguration.py
# Will get the default configuration, and replace every other
# found configuration with that default configuration
# (excluding the /config/ folder, for obvious reasons)

# There must be at least two items in each list for it to work
EXCLUDED_FOLDERS = (".git", "old", "api", "config", "notebook")
EXCLUDED_FILES = ("","Batteries\\Battery Log 12-13-14.xlsx")
DEFINITIONS = ("setting_twoMotors", "setting_noMotors", "setting_twoEncoders",
		"setting_noEncoders", "COMPASS", "INFRARED")
DEFAULT_CONFIG = "../Config/default_config.c"

import os
		
def main():
	defaultConfig = [line for line in getDefaultConfig()]
	modified = 0
	for file in getFiles():
		modified += replaceConfig(defaultConfig, file)
	print("%d configurations have been replaced" % modified)
		
def getDefaultConfig():
	for line in open(DEFAULT_CONFIG):
		if lineIsConfig(line):
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
	if "//USE DEFAULT CONFIG\n" in file:
		i = 0
		while lineIsConfig(file[i]):
			i += 1
		nonConfigLines = file[i:]
		fileobj.close()
		fileobj = open(filename, 'r+')
		fileobj.truncate()
		for line in defaultConfig:
			fileobj.write(line)
		for line in nonConfigLines:
			fileobj.write(line)
		fileobj.close()
		return 1
	else:
		fileobj.close()
		return 0
		
def lineIsConfig(line):
	return line.startswith("#pragma") or True in [line.startswith("#define " + definition) for definition in DEFINITIONS]
	#return true if the line starts with #pragma or if it's an accepted definition
		
def dirnameIsBanned(dirname):
	dirname = dirname.lower()
	return (True in ["".join(("\\",exFolder,"\\")).lower() in dirname or dirname.endswith("".join(("\\",exFolder)).lower()) for exFolder in EXCLUDED_FOLDERS])
	
def filenameIsBanned(filename, dirname):
	return (True in [os.path.join(dirname, filename) == os.path.join("..",exFile) for exFile in EXCLUDED_FILES])
	
main()