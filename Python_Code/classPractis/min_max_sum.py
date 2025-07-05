demo_arr=[]
n=int(input("Enter the range of the array: "))
for i in range(0,n):
    element=int(input("Enter element= "))
    demo_arr.append(element)
min_v=min(demo_arr)
max_v=max(demo_arr)
sum_v=sum(demo_arr)
print("Minimum= ",min_v)
print("Maximum= ",max_v)
print("Sum= ",sum_v)
sum=0
cum_sum=[]
for i in demo_arr:
    sum=sum+i
    cum_sum.append(sum)
print("Cumulative Sum= ",sum)
print("cumulative_array= ",cum_sum)
print(type(demo_arr))