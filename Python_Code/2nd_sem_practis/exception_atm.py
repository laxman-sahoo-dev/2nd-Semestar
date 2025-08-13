class myexception(Exception):
    def __init__(self,arg):
        self.arg=arg
def check(curr_amt,withdram_amt):
    if withdram_amt > curr_amt:
        raise myexception("Insufficient! You cannot withdraw more than your current balance.")
    else:
        curr_amt=curr_amt-withdram_amt
        print("current amount= ",curr_amt)
name=input("Enter name= ")
w_amt=int(input("Withdral amount- "))  
cur_amt=int(input("Current amount"))
try:
    check(cur_amt,w_amt)
except myexception as me:
    print(me)