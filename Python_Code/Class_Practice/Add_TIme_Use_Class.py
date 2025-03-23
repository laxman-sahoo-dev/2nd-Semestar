class Time:
    def __init__(self,hour,min,sec):
        self.hour=hour
        self.min=min
        self.sec=sec
    def __add__(self,ob2):
        return(self.hour+ob2.hour,self.min+ob2.min,self.sec+ob2.sec)
    def display(self):
        print("Hour= ",hour)
        print("Minute= ",min)
        print("Second= ",sec)
print("Input for 1st time object")
hour=int(input("Enter hour="))
min=int(input("Enter Minute="))
sec=int(input("Enter Second="))
ob1=Time(hour,min,sec)
print("\n\n")
print("Input for second object")
hour=int(input("Enter hour="))
min=int(input("Enter Minute="))
sec=int(input("Enter Second="))
ob2=Time(hour,min,sec)
hour,min,sec=ob1+ob2
if(sec>=60):
    temp=sec//60
    min=min+temp
    sec=sec%60
if(min>=60):
    temp=min//60
    hour=hour+temp
    min=min%60
ob3=Time(hour,min,sec)
ob3.display()

