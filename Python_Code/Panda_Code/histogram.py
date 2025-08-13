import matplotlib.pyplot as plt
import numpy as np

dataset=np.random.randn(1000)
print(dataset)

plt.hist(dataset,bins=100,color='blue',edgecolor='black')

plt.xlabel('value')
plt.ylabel('frequency')

plt.title('Number of values generated')
plt.show()