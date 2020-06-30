import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

dataset=pd.read_csv("Life_Expectancy_Data.csv")
new=dataset
dataset.columns
dataset.head()
dataset.describe()

features=['Country', 'Year', 'Status', 'Adult Mortality',
       'infant deaths', 'Alcohol', 'percentage expenditure', 'Hepatitis B',
       'Measles ', ' BMI ', 'under-five deaths ', 'Polio', 'Total expenditure',
       'Diphtheria ', ' HIV/AIDS', 'GDP', 'Population',
       ' thinness  1-19 years', ' thinness 5-9 years',
       'Income composition of resources', 'Schooling']


#Visualising the dataset
corr=dataset.corr()
sns.heatmap(corr, xticklabels=corr.columns, yticklabels=corr.columns)

#Data Cleaning

dataset.isna().sum()

countries=dataset.Country.unique()

dataset=dataset.interpolate(method="linear",limit_direction="forward")
new=dataset

#dataset.fillna(dataset.mean(axis=0), inplace=True)

#Finding outliers
newfeatures=['Adult Mortality','Life expectancy ',
       'infant deaths', 'Alcohol', 'percentage expenditure', 'Hepatitis B',
       'Measles ', ' BMI ', 'under-five deaths ', 'Polio', 'Total expenditure',
       'Diphtheria ', ' HIV/AIDS', 'GDP', 'Population',
       ' thinness  1-19 years', ' thinness 5-9 years',
       'Income composition of resources', 'Schooling']

for variable in newfeatures:
    q75, q25 = np.percentile(dataset[variable], [75 ,25])
    iqr = q75 - q25
    min_val = q25 - (iqr*1.5)
    max_val = q75 + (iqr*1.5)
    print("Number of outliers and percentage of it in {} : {} and {}".format(variable,
                                                                             len((np.where((dataset[variable] > max_val) | (dataset[variable] < min_val))[0])),
                                                                             len((np.where((dataset[variable] > max_val) | (dataset[variable] < min_val))[0]))*100/1987))
    
#Removing outliers
from scipy.stats.mstats import winsorize

dataset['Life expectancy '] = winsorize(dataset['Life expectancy '],(0.01,0))
dataset['Adult Mortality']= winsorize(dataset['Adult Mortality'],(0,0.03))
dataset['infant deaths'] = winsorize(dataset['infant deaths'],(0,0.10))
dataset['Alcohol'] = winsorize(dataset['Alcohol'],(0,0.01))
dataset['percentage expenditure']= winsorize(dataset['percentage expenditure'],(0,0.12))
dataset['Hepatitis B']= winsorize(dataset['Hepatitis B'],(0.11,0))
dataset['Measles '] = winsorize(dataset['Measles '],(0,0.19))
dataset['under-five deaths ']= winsorize(dataset['under-five deaths '],(0,0.12))
dataset['Polio'] = winsorize(dataset['Polio'],(0.09,0))
dataset['Total expenditure'] = winsorize(dataset['Total expenditure'],(0,0.01))
dataset['Diphtheria ']= winsorize(dataset['Diphtheria '],(0.10,0))
dataset[' HIV/AIDS'] = winsorize(dataset[' HIV/AIDS'],(0,0.16))
dataset['GDP'] = winsorize(dataset['GDP'],(0,0.13))
dataset['Population'] = winsorize(dataset['Population'],(0,0.14))
dataset[' thinness  1-19 years']= winsorize(dataset[' thinness  1-19 years'],(0,0.04))
dataset[' thinness 5-9 years'] = winsorize(dataset[' thinness 5-9 years'],(0,0.04))
dataset['Income composition of resources'] = winsorize(dataset['Income composition of resources'],(0.05,0))
dataset['Schooling'] = winsorize(dataset['Schooling'],(0.02,0.01))


#Encoding categorical data
status=pd.get_dummies(dataset.Status)
dataset=pd.concat([dataset,status], axis=1)
dataset=dataset.drop(["Status"], axis=1)

dataset=dataset.drop(['Country'], axis=1)

#Scaling the data
y=dataset['Life expectancy ']
X=dataset.drop(["Life expectancy "], axis=1)

"""from sklearn.preprocessing import MinMaxScaler
scaler=MinMaxScaler()
X=scaler.fit_transform(X)"""

#Splitting
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test= train_test_split(X,y, test_size=0.3, random_state=0)


#Modelling

#Linear Regression
from sklearn.linear_model import LinearRegression
regressor=LinearRegression()
regressor.fit(X_train,y_train)
prediction=regressor.predict(X_test)

from sklearn.metrics import r2_score, mean_absolute_error, mean_squared_error
print("R-2 score on training is: %.2f"% r2_score(y_test,prediction) )
print("Mean squared error: %.2f"%mean_squared_error(y_test, prediction))
print("Mean absolute error: %.2f"%mean_absolute_error(y_test, prediction))

plt.scatter(y_test, prediction)

dataset.columns

new=[[2014,271,58,0.01,73.5236,62,492,18.6,79,58,8.18,62,0.1,612.697,327582,14.6059,15.1,0.476,10,0,1]]
result=regressor.predict(new)
print(result)

new1=[[2009,281,58,0.01,56.7622,63,831,16.2,79,63,9.42,63,0.1,445.893,284331,14.6059,15.1,0.434,8.9,0,1]]
result1=regressor.predict(new1)
print(result1)
