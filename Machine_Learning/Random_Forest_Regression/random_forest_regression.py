# -*- coding: utf-8 -*-
"""
Created on Sat Mar  7 22:01:16 2020

@author: rhari
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataset = pd.read_csv('Position_Salaries.csv')
X = dataset.iloc[:, 1:2].values
y = dataset.iloc[:, 2].values

#Creating and Fitting the regressor
from sklearn.ensemble import RandomForestRegressor
regressor=RandomForestRegressor(n_estimators= 300, random_state =0)
regressor.fit(X,y)

y_pred=regressor.predict(np.array(6.5).reshape(1,1))

#Visualising the regression results
X_grid=np.arange(min(X), max(X), 0.01)
X_grid=X_grid.reshape((len(X_grid),1))
plt.scatter(X, y, color='red')
plt.plot(X_grid, regressor.predict(X_grid), color='blue')
plt.title('Truth or Bluff( Random Forest Regression Model)')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()


