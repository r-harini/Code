# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 22:43:39 2020

@author: rhari
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataset=pd.read_csv('Position_Salaries.csv')
X=dataset.iloc[:, 1:2].values
y=dataset.iloc[:,2].values

#Fitting the Decision Tree Regression Model to the dataset
from sklearn.tree import DecisionTreeRegressor
regressor=DecisionTreeRegressor(random_state=0)
regressor.fit(X,y)

#Predicting a new result
y_pred=regressor.predict(np.array(6.5).reshape(1,1))

#Visualising the Decision Tree Regression results
X_grid=np.arange(min(X), max(X), 0.01)
X_grid=X_grid.reshape((len(X_grid),1))
plt.scatter(X, y, color='red')
plt.plot(X_grid, regressor.predict(X_grid), color='blue')
plt.title('Truth or Bluff')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()
