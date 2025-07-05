class Base:
	def input(self):
		self.num1 = int(input("Enter 1st number: "))
class child(Base):
	def get(self):
		self.num2 = int(input("Enter second number : "))
	def find_large(self):
		if(self.num1>self.num2):
			return self.num1
		else:
			return self.num2
	def display(self,la):
		print(la)

ob=child()
ob.input()
ob.get()
la=ob.find_large()
ob.display(la)