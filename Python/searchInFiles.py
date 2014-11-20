# searchInFiles.py
# used to search for a string of characters in a specified list of files

deprecated = False
repeatInfinite = True
caseSensitive = False

def main():
	print("What phrase would you like to search for?")
	searchPhrase = input()

	if not caseSensitive:
		searchPhrase = searchPhrase.lower()
	
	#print("What folder do you want to look in? Type 'all' for all folders.")
	#searchFolder = input()

	print()

	filesToSearch = []
	for filename in open('../List of files.txt'):
		if len(filename) > 2:
   			filesToSearch.append(filename[:-1])

	'''		
	for file in filesToSearch:
		if (file[:len(searchFolder)-1] == searchFolder):
			print("removed %s" % file)
			filesToSearch.remove(file)
	'''
	
	#print(filesToSearch)
	found = []

	for file in filesToSearch:
		openedFile = open('../' + file)
		lineNum = 0
		for line in openedFile:
	   		lineNum += 1
	   		if searchPhrase in line.lower():
	   			found.append([file, lineNum])
		
	#print(found)

	if len(found) > 0:
		print("\"%s\" appears in %d places...\n" % (searchPhrase, len(found)))
		for place in found:
   			print("Line %d in %s" % (place[1], place[0]))
	else:
   		print("Sorry, but \"%s\" was not found in any known files" % searchPhrase)
	print()

def complainAboutDeprecation():
	print("You know, in the git shell, there is a very\n"
	   + "useful command, called `git grep' that will do exactly what this\n"
	   + "program does, but without all of the hassle of python and all of\n"
	   + "the errors that Zach makes. It is for that reason that this\n"
	   + "program has been deprecated. Please use git grep instead.\n")
	   
if not deprecated:
	while repeatInfinite:
		main()
	main()
else:
	complainAboutDeprecation()