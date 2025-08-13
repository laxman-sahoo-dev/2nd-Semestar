n=int(input("Enter no of row- "))
i=0
while(i!=n):
    for j in range(0,n-i-1):
        print(" ",end=" ")
    for k in range(i,-1,-1):
        print("%c"%(k+65),end=" ")
    for l in range(1,i+1):
        print("%c"%(l+65),end=" ")
    print()
    i=i+1
    