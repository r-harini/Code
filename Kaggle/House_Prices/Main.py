# -*- coding: utf-8 -*-
"""
Created on Wed Feb 26 16:33:19 2020

@author: rhari
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

data=pd.read_csv('train.csv')
test=pd.read_csv('test.csv')

data.head()
data.describe()

data.isnull().sum().sort_values(ascending=False)
null_values=data.isnull().sum()
null_values.plot.bar()

#Splitting variables
X=test.iloc[:,:-1]
y=test.iloc[:,-1]


#Visualising the dataset
plt.scatter(data['LotFrontage'],y, color='red')

#Finding the categorical and numerical variables
categorical_features=data.select_dtypes(include=['object']).columns
categorical_features


numerical_features=data.select_dtypes(exclude=['object']).columns
numerical_features
data[numerical_features].isnull().values.sum()

data_num=data[numerical_features]
data_cat=data[categorical_features]

#Replacing the null values
data_num.isnull().values.sum()
data_num=data_num.fillna(data_num.median())
data_num.isnull().values.sum()

numerical_features=test.select_dtypes(exclude=['object']).columns
categorical_features=test.select_dtypes(include=['object']).columns
test_num=test[numerical_features]
test_cat=test[categorical_features]

test_num.isnull().values.sum()
test_num=test_num.fillna(test_num.median())
test_num.isnull().values.sum()


from scipy.stats import skew
skewness=data_num.apply(lambda x:skew(x))
skewness.sort_values(ascending=False)
skewness=skewness[abs(skewness)>0.5]
skewness.index

test_skewness=test_num.apply(lambda x:skew(x))
test_skewness.sort_values(ascending=False)
test_skewness=test_skewness[abs(test_skewness)>0.5]

skew_features=data[skewness.index]
skew_features.columns
skew_features=np.log1p(skew_features)
data_cat.shape
data_cat=pd.get_dummies(data_cat)


#Applying the modelling
from sklearn.model_selection import cross_val_score, train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, make_scorer

data=pd.concat([data_cat, data_num], axis=1)

X_train, X_test, y_train, y_test= train_test_split(data, y, test_size=0.3, random_state=0)

n_folds=5
from sklearn.model_selection import KFold
scorer=make_scorer(mean_squared_error, greater_is_better=False)

def rmse_CV_train(model):
    kf=KFold(n_folds, shuffle=True, random_state=42).get_n_splits(data.values)
    rmse=np.sqrt(-cross_val_score(model, X_train, y_train, scoring="neg_mean_squared_error", cv=kf))
    return (rmse)

def rmse_CV_test(model):
    kf=KFold(n_folds, shuffle=True, random_state=42).get_n_splits(data.values)
    rmse=np.sqrt(-cross_val_score(model, X_test, y_test, scoring="neg_mean_squared_error", cv=kf))
    return (rmse)

lr=LinearRegression()
lr.fit(X_train, y_train)
y_test_pred=lr.predict(X_test)

#Visualising predicted values
plt.scatter(y_test_pred,y_test, c="black", label="Testing data")
plt.title("Linear regression")
plt.show()