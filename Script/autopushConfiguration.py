# autopushConfiguration.py
# Will get the default configuration, and replace every other
# found configuration with that default configuration
# (excluding the /config/ folder, for obvious reasons)

import common

common.EXCLUDED_FOLDERS = (".git", "old", "api", "config", "notebook")

DEFINITIONS = ("setting_twoMotors", "setting_noMotors", "setting_twoEncoders",
		"setting_noEncoders", "COMPASS", "INFRARED")
DEFAULT_CONFIG = "../Config/default_config.c"
TIMESTAMP_PREFACE = "//Configuration is current as of "
ROBOTC_DISCLAIMER = "//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//\n"

def main():
	defaultConfig = [line for line in getDefaultConfig()]
	modified = 0
	for file in common.getFiles(common.fileIsC):
		modified += replaceConfig(defaultConfig, file)
	print("%d configurations have been replaced" % modified)
		
def getDefaultConfig():
	for line in open(DEFAULT_CONFIG):
		if lineIsConfig(line):
			yield line
			
def replaceConfig(defaultConfig, filename):
	fileobj = open(filename, 'r')
	file = [line for line in fileobj]
	if "//USE DEFAULT CONFIG\n" in file:
		i = 0
		while lineIsConfig(file[i]):
			i += 1
		nonConfigLines = file[i:]
		# Just in case, check the file for any bad config lines. Just to keep it pretty.
		for line in nonConfigLines:
			if lineIsConfig(line):
				nonConfigLines.remove(line)
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
	return line.startswith("#pragma") or lineIsDefine(line) or lineIsDisclaimer(line) or lineIsTimestamp(line) #return true if the line starts with #pragma or if it's an accepted definition
	
def lineIsDefine(line):
	for definition in DEFINITIONS:
		if line.startswith("#define " + definition + " "):
			return True
		if line == "#define " + definition:
			return True
		if line == "#define " + definition + "\n":
			return True
	return False
	
def lineIsDisclaimer(line):
	return line == ROBOTC_DISCLAIMER

def lineIsTimestamp(line):
	return line.startswith(TIMESTAMP_PREFACE)
	
main()