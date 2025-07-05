fp=open("MyFile1.txt","w")
data=input("Enter text to write into the file & @ to stop- ")
while(data!="@"):
    fp.write(data + '\n')
    data=input()
fp.close()
fp=open("MyFile1.txt","r")
data=fp.read()
print("The content of file : ",data)
fp.close()
 
