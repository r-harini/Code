# -*- coding: utf-8 -*-
"""
Created on Wed Dec  4 19:30:06 2019

@author: rhari
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

dataset=pd.read_csv('Position_Salaries.csv')
X=dataset.iloc[:,1:2].values
y=dataset.iloc[:,2].values

"""from sklearn.model_selection import train_test_split
X-train, X_test, y_train, y-test=train-test-split(X,y,test_size=0.2, random_state=0)"""

from sklearn.linear_model import LinearRegression
lin_reg=LinearRegression()
lin_reg.fit(X,y)

from sklearn.preprocessing import PolynomialFeatures
poly_reg=PolynomialFeatures(degree=4)
X_poly=poly_reg.fit_transform(X)
lin_reg_2=LinearRegression()
lin_reg_2.fit(X_poly, y)

#Visiualising the Linear Regression Model
plt.scatter(X,y, color='red')
plt.plot(X, lin_reg.predict(X), color='blue')
plt.title('Truth or Bluff(Linear Regression)')
plt.xlabel('Position level')
plt.ylabel('Salary')
plt.show()

#Visualising the Polynomial Regression Model
plt.scatter(X, y, color='red')
plt.plot(X, lin_reg_2.predict(poly_reg.fit_transform(X)), color='blue')
plt.title('Truth or Bluff(Polynonial Regression)')
plt.xlabel('Position level')
plt.ylabel('Salary')
plt.show()

#Predicting a new result with Linear Regression
lin_reg.predict(np.reshape(6.5,(1,1)))

#Predicting a new result with Polynomial Regression
lin_reg_2.predict(poly_reg.fit_transform(np.reshape(6.5,(1,1))))
