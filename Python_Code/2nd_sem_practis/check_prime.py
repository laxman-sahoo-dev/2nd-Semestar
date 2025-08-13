num=int(input("Enter a number-"))
'''count=0
for i in range(1,num+1):
    if num % i==0:
        count+=1
if(count==2):
    print("Prime")
else:
    print("Not prime")
    '''
    
num1=int(input("2nd number-"))
print("prime number are-",end="   ")
for i in range(num,num1+1):
    count=0
    for j in range(1,i+1):
        if i%j==0:
            count+=1
    if(count==2):
        print(i,end=",")