'''num=int(input("Enter a number- "))
reverse=0
num1=num
while(num):
    dg=num%10
    reverse=reverse*10+dg
    num=num//10
if(reverse==num1):
    print("Palllendrom")
else:
    print("not")'''
    
num=int(input("Enter a number-"))
st=str(num)
rst=st[::-1]
rst=int(rst)
if(rst==num):
    print("pallen")
else:
    print("not")