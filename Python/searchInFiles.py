true = False
# searchInFiles.py
# used to search for a string of characters in a specified list of files

deprecated = true

print("This program has been deprecated!\n")

def complainAboutDeprecation():
	print("You know, in the git shell, there is a very\n")
	   + "useful command, called `git grep' that will do exactly what this\n"
	   + "program does, but without all of the hassle of python and all of\n"
	   + "the errors that Zach makes. It is for that reason that this\n"
	   + "program has been deprecated. Please use git grep instead.\n")

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

if not deprecated:
   main()
