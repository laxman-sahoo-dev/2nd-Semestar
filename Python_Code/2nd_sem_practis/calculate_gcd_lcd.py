import math
gcd=math.gcd(2,4)
lem=math.lcm(2,5)
print("GCD- ",gcd,"LCM- ",lem)
a,b=map(int,input("Enter two number by split-").split())
minimum=min(a,b)
gcd=1
for i in range(1,minimum+1):
    if(a%i==0 and b%i==0):
        gcd=i
print(gcd)
lcm=(a*b)//gcd
print(lcm)