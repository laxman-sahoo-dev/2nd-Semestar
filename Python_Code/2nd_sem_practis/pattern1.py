n=int(input("Enter the no of row-"))
j=0
while(j!=n):
    for i in range(n-j-1):
        print(" ",end=" ")
    for i in range(1,j+2):
        print(j+1,end=" ")

    print()
    j+=1