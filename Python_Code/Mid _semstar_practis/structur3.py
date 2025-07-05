r=int(input("Enter the nuber of rows: "))
for i in range(r):
        j=r-i-1
        while(j>0):
                print("   ",end="")        	
                j-=1
        k=i
        while(k>=0):
                print(" %c "%(k+65),end="")
                k -=1
        c=1
        while(c<=i):
                print(" %c "%(c+65),end="")
                c+=1
                print()
