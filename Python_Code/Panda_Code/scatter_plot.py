import matplotlib.pyplot as plt
import numpy as np
x1=np.array([160,165,170,175,180,185,190,195,200,205])
y1=np.array([55,58,60,62,64,66,68,70,72,75])
x2=np.array([150,155,160,165,170,175,180,195])
y2=np.array([50,52,54,56,58,64,66,68])

plt.scatter(x1,y1,color='blue',label='first')
plt.scatter(x2,y2,color='red',label='second')

plt.xlabel('Hight(cm)')
plt.ylabel('weight(kg)')

plt.title('compare of height & weight of two group')

plt.legend()
plt.show()
