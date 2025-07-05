class complex:
	def __init__(self):
		self.real=int(input("Enter real number: "))
		self.img=int(input("Enter imaginary number:"))
	def shownumber(self):
		print(f"{self.real}i + {self.img}j")

	def __add__(self,ob2):
		return(self.real+ob2.real,ob2.img+self.img)

ob1=complex()
ob1.shownumber()
ob2=complex()
ob2.shownumber()
r,i=ob1+ob2
print(f"SUM= {r}i + {i}j")