'''arr=[]
n=int(input("Enter the size of the array: "))
for i in range(0,n):
    element=int(input("Enter element : "))
    arr.append(element)
print(arr)
print(type(arr))'''
n = int(input("Enter number of elements: "))
arr = []
for _ in range(n):
    element = input("Enter element: ")  # or int(input()) if numbers
    arr.append(element)
print(arr)
print(type(arr))