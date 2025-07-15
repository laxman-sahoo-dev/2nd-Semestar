import matplotlib.pyplot as plt
import numpy as np

dataset=np.array([12,12,13,14,15,16,17,15,17])
print(dataset)

plt.hist(dataset,bins=30,color='blue',edgecolor='black')

plt.xlabel('value')
plt.ylabel('frequency')

plt.title('Number of values generated')
plt.show()