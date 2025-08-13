import pandas as pd
import matplotlib.pyplot as plt

 
dataset = {
    'year': [2020, 2021, 2022, 2023, 2024],
    'covid_data': [25, 35, 45,20, 10],
    'heart_disease_data': [35, 40, 55, 60,65]
}

# Create DataFrame
dframe = pd.DataFrame(dataset)

# Plot data
dframe.plot(x='year', y=['covid_data', 'heart_disease_data'], title='Infected people over time')

# Show plot
plt.show()
