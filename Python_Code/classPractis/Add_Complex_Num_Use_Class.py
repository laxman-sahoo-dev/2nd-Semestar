class complex:
    def __init__(self):
        self.real=int(input("Enter real number= "))
        self.img =int(input("Enter imaginary number: "))
    def shownumber(self):
        print(self.real,"i + ",self.img,"j")
    def __add__(self,ob2):
        return(self.real+ob2.real,
        self.img+ob2.img)
ob1=complex()
ob1.shownumber()
ob2=complex()
ob2.shownumber()
i,j=ob1+ob2
print(f"{i}i+{j}j")
