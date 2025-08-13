class a:
    def __init__(self,val_a):
        self.val_a=val_a
class b(a):
    def __init__(self,val_b,val_a):
        super().__init__(val_a)
        self.val_b=val_b
class c:
    def __init__(self,val_c):
        self.val_c=val_c
class d(b,c):
    def __init__(self,val_a,val_b,val_c,val_d):
        b.__init__(self,val_b,val_c)
        c.__init__(self,val_c)
        self.val_d=val_d
    def average(self):
        self.avg=(self.val_a+self.val_b+self.val_c+self.val_d)/4
    def display(self):
        print("Average= ",self.avg)
n1,n2,n3,n4=map(int,input("Enter 4 number- ").split())
obj=d(n1,n2,n3,n4)
obj.average()
obj.display()