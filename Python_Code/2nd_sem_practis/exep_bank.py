class myexeption(Exception):
    def __init__(self,arg):
        self.arg=arg
def check(bank):
    for key,value in bank.items():
        print(f"Name={key}   Balance={value}")
        if(value<2000):
            raise myexeption("Balance is less than 2000")
bank={}
n=int(input("How many item input:"))
for i in range(n):
    key=input("Enter key: ")
    value=int(input("Enter value: "))
    bank[key]=value
try:
    check(bank)
except myexeption as me:
    print(me)