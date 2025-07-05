class student:
	def __init__(self,n,m):
		self.name=n
		self.mark=m
	def display(self):
		print("NAME= ",self.name)
		print("MARK= ",self.mark)

def top_student(s1,s2):
	if(s1.mark>s2.mark):
		return s1
	else:
		return s2

name=input("Enter 1ststudent name: ")
mark=float(input("Enter 1ststudent mark: "))
ob1=student(name,mark)
name=input("Enter 2nd student name: ")
mark=float(input("Enter 2nd student mark: "))
ob2=student(name,mark)
print("\n")
print("Student Details-")
ob1.display()
ob2.display()
ob3=top_student(ob1,ob2)
print("The top student: ")
ob3.display()