class person:
	def __init__(self,age,we,hi):
		self.age=age
		self.weight=we
		self.height=hi
	def calculate(self):
		bmi=self.weight/(self.height**2)
		if(bmi<18.5):
			print("UNDER WEIGHT")
		if(18.5>=bmi<24.9)