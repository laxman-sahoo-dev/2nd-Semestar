class A:
	def __init__(self,va):
		self.va=va
class B(A):
	def __init__(self,va,vb):
		super().__init__(va)
		self.vb=vb
class C:
	def __init__(self,vc):
		self.vc=vc
class D(B,C):
	def __init__(self, va, vb,vc,vd):
		B.__init__(self,va, vb)
		C.__init__(self,vc)
		self.vd=vd

	def average(self):
		return(self.va+self.vb+self.vc+self.vd/4)
	def display(self,total):
		print(total)

n1=int(input("Enter 1 number: "))
n2=int(input("Enter 2 number: "))
n3=int(input("Enter 3 number: "))
n4=int(input("Enter 4 number: "))
ob=D(n1,n2,n3,n4)
total=ob.average()
ob.display(total)