# searchInFiles.py
# used to search for a string of characters in a specified list of files

print("You know, in the git shell, there is a very")
print("useful command, called `git grep' that will")
print("do exactly what this program does, but without")
print("all of the hassle of python.")
print("it is for that reason that this program has been")
print("deprecated.")
print("Please use git grep instead.")

depracated = True

def main():
	print("What phrase would you like to search for?")
	searchPhrase = input()

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
			if searchPhrase in line:
				found.append([file, lineNum])
			
	#print(found)

	if len(found) > 0:
		print("\"%s\" appears at..." % searchPhrase)
		for place in found:
			print("Line %d in %s" % (place[1], place[0]))
	else:
		print("Sorry, but %s was not found in any known files" % searchPhrase)

if depracated == False:
	main()
