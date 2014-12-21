# linesWritten.py
# Returns how many lines of code exist in it's path.

# Please keep this list alphebetized

print("This program has been deprecated!")
print("The command `wc -l $(git ls-files)'")
print("Performs the same function. If you")
print("only want to read the lines of executable")
print("code use the command: ")
print("`wc -l $(cat \".\List of Files.txt\"'")
print("\nUnlike searchInFiles.py this program will")
print("not be deleted as the commands are not simple.")
print("\nCAUTION!!! The count is not accurate!")

def lengthOf(filename):
	try:
		return sum(1 for line in open('../' + filename))
	except:
		print("There was an error and %s could not be read" % filename)
		return 0;

# Main code

lines = 0
for filename in open('../List of files.txt'):
	if len(filename) > 2:
		file = filename[:-1]
		lines += lengthOf(file)
	
print("All the specified files contain a total of %d lines of code" % lines)

#wc can also count words, bytes, length of longes line, and characters.
#The last time I (Daniel) checked we had about 100 KiB of code (99.88281250 KiB) and 10708 words.