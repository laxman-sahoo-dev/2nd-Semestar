class complex:
	def __init__(self,r,i):
		self.real=r
		self.img=i
	def shownumber(self):
		print(f"{self.real}i + {self.img}j")

	def __add__(self,ob2):
		return(self.real+ob2.real,ob2.img+self.img)
	def calculate(self):
		print(f"SUM={r}i + {i}j")
real=int(input("Enter real number: "))
img=int(input("Enter imaginary number:"))
ob1=complex(real,img)
ob1.shownumber()
real=int(input("Enter real number: "))
img=int(input("Enter imaginary number:"))
ob2=complex(real,img)
ob2.shownumber()
r,i=ob1+ob2
ob3=complex(r,i)
ob3.calculate()