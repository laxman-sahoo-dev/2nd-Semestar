class student:
	def input(self):
		self.real=int(input("Enter real number: "))
		self.img=int(input("Enter imaginary number: "))
	def display(self):
		print(f"{self.real}i + {self.img}j")
	def calculate(self,ob1,ob2):
		print(self)
		r=ob1.real+ob2.real
		i=ob1.img+ob2.img
		return(r,i)
	def sum(self,r,i):
		print(f"SUM = {r}i + {i}j")
ob1=student()
ob2=student()
ob1.input()
ob1.display()
ob2.input()
ob2.display()
ob3=student()
r,i=ob3.calculate(ob1,ob2)
ob3.sum(r,i)