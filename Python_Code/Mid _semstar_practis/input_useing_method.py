class student:
	def input(self):
		self.name=input("Enter student name= ")
		self.mark=int(input("Enter Mark = "))
	def display(self):
		print("NAME= ",self.name)
		print("MARK= ",self.mark)

def top_student(s1,s2):
	if(s1.mark>s2.mark):
		return s1
	else:
		return s2

ob1=student()
ob1.input()
ob2=student()
ob2.input()
print("\n")
print("Student Details-")
ob1.display()
ob2.display()
ob3=top_student(ob1,ob2)
print("The top student: ")
ob3.display()
