fp = open("MyFile1.txt", "r")

# Move pointer to the end of the file
fp.seek(0, 2)         # Like fseek(fp, 0, SEEK_END)
tail = fp.tell()      # Get current file position (end = file size in characters)
print("File size (characters):", tail)

# Move pointer back to the beginning
fp.seek(0)            # Reset to beginning of file
data = fp.read()      # Read full content

# Count stats
word_count = len(data.split())
space_count = data.count(' ')
newline_count = data.count('\n')

# Display results
print(f"\nTOTAL:\nWords = {word_count}\tSpaces = {space_count}\tNew Lines = {newline_count}")
fp.seek(3,0)
data=fp.read()
print("\nThe content of the file:\n", data)
fp.close()
