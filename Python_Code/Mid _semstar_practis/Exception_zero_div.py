try:
	a= int(input("Enter a= "))
	b=int(input("Enter b= "))
	c=a/b
	print("Result= ",c)
except ZeroDivisionError:
	print("Division by zero is not allowed")
else:
	print("There is no error")
finally:
	print("Program execution completed")