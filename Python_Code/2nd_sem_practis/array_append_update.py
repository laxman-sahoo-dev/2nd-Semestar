import numpy as np

# Create initial array
arr = np.array([10, 20, 30, 40])
print("Original array:", arr)

# ✅ 1. Adding elements (using np.append)
arr = np.append(arr, 50)
print("After appending 50:", arr)

# You can also add multiple elements
arr = np.append(arr, [60, 70])
print("After adding 60, 70:", arr)

# ✅ 2. Changing value at a specific index
arr[2] = 300   # Change the third element (index 2)
print("After changing index 2 to 300:", arr)
arr[3:5]=np.array([22,33])
print(arr)