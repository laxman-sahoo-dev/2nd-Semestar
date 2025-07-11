import pandas as pd
import matplotlib.pyplot as plt

dataset={'student_year':['year1','year2','year3','year4','year5'],
         'pass_percentage':[65,75,78,45,37]}

dframe=pd.DataFrame(dataset)
dframe.plot.bar (x='student_year',y='pass_percentage',title='Result analysis', rot=90 ,color='red' )
plt.show()