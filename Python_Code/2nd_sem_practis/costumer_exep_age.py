class myexception(Exception):
    def __init__(self,arg):
        self.arg=arg
def check(age):
    if(age<18):
        raise myexception("You under 18 not eligible to vote")
try:
    age=int(input("Enter age-"))
    check(age)
except myexception as me:
    print(me)
