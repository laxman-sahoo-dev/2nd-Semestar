def prime(num):
	count=0
	for i in range(1,num+1):
		if(num%i==0):
			count=count+1
	if(count==2):
		return True

n1=int(input("Enter from: "))
n2=int(input("Enter to= "))
j=0
for i in range(n1,n2+1):
	flag =prime(i)
	if(flag==True):
		print(i,end=" ")
		j=j+1
if(j==0):
	print("There is no prime number")