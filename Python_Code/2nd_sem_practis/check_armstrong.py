num=int(input("Enter a number-"))
digit=len(str(num))
sum=dg=0
num1=num
while(num):
    dg=num%10
    sum=sum+(dg**digit)
    num=num//10
if(num1==sum):
    print("Armstrong")
else:
    print("Not armstrong")