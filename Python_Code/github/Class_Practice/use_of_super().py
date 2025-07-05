class person:
    def __init__(self,name,age):
        self.name=name
        self.age=age
class Employee(person):
    def __init__(self,id,deg,name,age):
        super().__init__(name,age)
        self.id=id
        self.deg=deg
class EmployeeDetails(Employee):
    def __init__(self,basic,id,deg,name,age):
        super().__init__(id,deg,name,age)
        self.basic=basic
    def calculate(self):
        if(self.basic<=5000):
            ta=self.basic*.03
            da=self.basic*.04
            tax=self.basic*.01
        if(self.basic > 5000 and self.basic<=10000):
            ta=self.basic*.05
            da=self.basic*.07
            tax=self.basic*.02
        if(self.basic > 10000):
             ta=self.basic*.07
             da=self.basic*.09
             tax=self.basic*.04
        at=ta+da+tax
        self.total=self.basic-at
    def display (self,name):
        print("Name=",name)
        print("Total Balance= ",self.total)
name=input("Enter name= ")
age=int(input("Enter age= "))
id=int(input("Enter Id= "))
deg=input("Enter designation=")
basic=int(input("Enter basic salary="))
ob=EmployeeDetails(basic,id,deg,name,age)
ob.calculate()
ob.display(name)
