class Time:
	def input(self):
		self.hour=int(input("Enter hour= "))
		self.min=int(input("Enter Minute= "))
		self.sec=int(input("Enter Second= "))
	def __add__(self,obj2):
		return(self.hour+obj2.hour,self.min+obj2.min,self.sec+obj2.sec)
	def display(self,hour,min,sec):
		print("HOUR= ",hour)
		print("MINUTE= ",min)
		print("SECOND= ",sec)

obj1=Time()
obj1.input()
obj2=Time()
obj2.input()
hour,min,sec=obj1+obj2
if(sec>=60):
	temp=sec//60
	min=min+temp
	sec=sec%60
if(min>=60):
	temp=min//60
	hour=hour+temp
	min=min%60
obj2.display(hour,min,sec)
