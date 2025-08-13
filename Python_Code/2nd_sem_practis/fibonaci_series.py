num=int(input("Enter the number of terms- "))
a,b=0,1
item=0
for i in range (num):
    print(a,end="," if i < num-1 else "")
    a,b=b,a+b
'''def fibo(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        return fibo(n-1)+fibo(n-2)
print(fibo(10))'''