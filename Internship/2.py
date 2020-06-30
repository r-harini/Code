# -*- coding: utf-8 -*-
"""
Created on Wed May 20 21:21:21 2020

@author: rhari
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from scipy.stats.mstats import winsorize
import scipy.stats as stats
import warnings
warnings.filterwarnings('ignore')
%matplotlib inline

life = pd.read_csv('Life_Expectancy_Data.csv')

country_list = life.Country.unique()
fill_list = ['Country', 'Year', 'Status', 'Life expectancy ', 'Adult Mortality',
       'infant deaths', 'Alcohol', 'percentage expenditure', 'Hepatitis B',
       'Measles ', ' BMI ', 'under-five deaths ', 'Polio', 'Total expenditure',
       'Diphtheria ', ' HIV/AIDS', 'GDP', 'Population',
       ' thinness  1-19 years', ' thinness 5-9 years',
       'Income composition of resources', 'Schooling']

for country in country_list:
    life.loc[life['Country'] == country,fill_list] = life.loc[life['Country'] == country,fill_list].interpolate()
life.dropna(inplace=True)

col_dict = {'Life expectancy ':1 , 'Adult Mortality':2 ,
        'Alcohol':3 , 'percentage expenditure': 4, 'Hepatitis B': 5,
       'Measles ' : 6, ' BMI ': 7, 'under-five deaths ' : 8, 'Polio' : 9, 'Total expenditure' :10,
       'Diphtheria ':11, ' HIV/AIDS':12, 'GDP':13, 'Population' :14,
       ' thinness  1-19 years' :15, ' thinness 5-9 years' :16,
       'Income composition of resources' : 17, 'Schooling' :18, 'infant deaths':19}

for variable in col_dict.keys():
    q75, q25 = np.percentile(life[variable], [75 ,25])
    iqr = q75 - q25
    min_val = q25 - (iqr*1.5)
    max_val = q75 + (iqr*1.5)
    print("Number of outliers and percentage of it in {} : {} and {}".format(variable,
                                                                             len((np.where((life[variable] > max_val) | (life[variable] < min_val))[0])),
                                                                             len((np.where((life[variable] > max_val) | (life[variable] < min_val))[0]))*100/1987))
    
winsorized_Life_Expectancy = winsorize(life['Life expectancy '],(0.01,0))
winsorized_Adult_Mortality = winsorize(life['Adult Mortality'],(0,0.03))
winsorized_Infant_Deaths = winsorize(life['infant deaths'],(0,0.10))
winsorized_Alcohol = winsorize(life['Alcohol'],(0,0.01))
original_Percentage_Exp = life['percentage expenditure']
winsorized_Percentage_Exp = winsorize(life['percentage expenditure'],(0,0.12))
winsorized_HepatitisB = winsorize(life['Hepatitis B'],(0.11,0))
original_Measles = life['Measles ']
winsorized_Measles = winsorize(life['Measles '],(0,0.19))
original_Under_Five_Deaths = life['under-five deaths ']
winsorized_Under_Five_Deaths = winsorize(life['under-five deaths '],(0,0.12))
winsorized_Polio = winsorize(life['Polio'],(0.09,0))
original_Tot_Exp = life['Total expenditure']
winsorized_Tot_Exp = winsorize(life['Total expenditure'],(0,0.01))
winsorized_Diphtheria = winsorize(life['Diphtheria '],(0.10,0))
winsorized_HIV = winsorize(life[' HIV/AIDS'],(0,0.16))
winsorized_GDP = winsorize(life['GDP'],(0,0.13))
winsorized_Population = winsorize(life['Population'],(0,0.14))
winsorized_thinness_1to19_years = winsorize(life[' thinness  1-19 years'],(0,0.04))
winsorized_thinness_5to9_years = winsorize(life[' thinness 5-9 years'],(0,0.04))
winsorized_Income_Comp_Of_Resources = winsorize(life['Income composition of resources'],(0.05,0))
winsorized_Schooling = winsorize(life['Schooling'],(0.02,0.01))

winsorized_list = [winsorized_Life_Expectancy,winsorized_Adult_Mortality,winsorized_Alcohol,winsorized_Measles,winsorized_Infant_Deaths,
            winsorized_Percentage_Exp,winsorized_HepatitisB,winsorized_Under_Five_Deaths,winsorized_Polio,winsorized_Tot_Exp,winsorized_Diphtheria,winsorized_HIV,winsorized_GDP,winsorized_Population,winsorized_thinness_1to19_years,winsorized_thinness_5to9_years,winsorized_Income_Comp_Of_Resources,winsorized_Schooling]

for variable in winsorized_list:
    q75, q25 = np.percentile(variable, [75 ,25])
    iqr = q75 - q25

    min_val = q25 - (iqr*1.5)
    max_val = q75 + (iqr*1.5)
    
    print("Number of outliers after winsorization in  : {} ".format(len(np.where((variable > max_val) | (variable < min_val))[0])))    

life['winsorized_Life_Expectancy'] = winsorized_Life_Expectancy
life['winsorized_Adult_Mortality'] = winsorized_Adult_Mortality
life['winsorized_Infant_Deaths'] = winsorized_Infant_Deaths
life['winsorized_Alcohol'] = winsorized_Alcohol
life['winsorized_Percentage_Exp'] = winsorized_Percentage_Exp
life['winsorized_HepatitisB'] = winsorized_HepatitisB
life['winsorized_Under_Five_Deaths'] = winsorized_Under_Five_Deaths
life['winsorized_Polio'] = winsorized_Polio
life['winsorized_Tot_Exp'] = winsorized_Tot_Exp
life['winsorized_Diphtheria'] = winsorized_Diphtheria
life['winsorized_HIV'] = winsorized_HIV
life['winsorized_GDP'] = winsorized_GDP
life['winsorized_Population'] = winsorized_Population
life['winsorized_thinness_1to19_years'] = winsorized_thinness_1to19_years
life['winsorized_thinness_5to9_years'] = winsorized_thinness_5to9_years
life['winsorized_Income_Comp_Of_Resources'] = winsorized_Income_Comp_Of_Resources
life['winsorized_Schooling'] = winsorized_Schooling
life['winsorized_Measles'] = winsorized_Measles

all_col = ['Life expectancy ','winsorized_Life_Expectancy','Adult Mortality','winsorized_Adult_Mortality','infant deaths',
         'winsorized_Infant_Deaths','Alcohol','winsorized_Alcohol','percentage expenditure','winsorized_Percentage_Exp','Hepatitis B',
         'winsorized_HepatitisB','under-five deaths ','winsorized_Under_Five_Deaths','Polio','winsorized_Polio','Total expenditure',
         'winsorized_Tot_Exp','Diphtheria ','winsorized_Diphtheria',' HIV/AIDS','winsorized_HIV','GDP','winsorized_GDP',
         'Population','winsorized_Population',' thinness  1-19 years','winsorized_thinness_1to19_years',' thinness 5-9 years',
         'winsorized_thinness_5to9_years','Income composition of resources','winsorized_Income_Comp_Of_Resources',
         'Schooling','winsorized_Schooling','Measles ','winsorized_Measles','GDP','winsorized_GDP']

round(life[['Status','Life expectancy ']].groupby(['Status']).mean(),2)

stats.ttest_ind(life.loc[life['Status']=='Developed','Life expectancy '],life.loc[life['Status']=='Developing','Life expectancy '])

feature_df = life[['Status','winsorized_Life_Expectancy','winsorized_Income_Comp_Of_Resources','winsorized_HIV','winsorized_Adult_Mortality']]
feature_df = pd.concat([feature_df,pd.get_dummies(feature_df['Status'],drop_first=True)],axis=1)
final = feature_df.drop('Status',axis=1)
final.sample(10)

life = pd.concat([life,pd.get_dummies(life['Status'],drop_first=True)],axis=1)
life = life.drop('Status',axis=1)
life.sample(10)

X= life[['Country','winsorized_Adult_Mortality',
       'winsorized_Infant_Deaths', 'winsorized_Alcohol',
       'winsorized_Percentage_Exp', 'winsorized_HepatitisB',
       'winsorized_Under_Five_Deaths', 'winsorized_Polio',
       'winsorized_Tot_Exp', 'winsorized_Diphtheria', 'winsorized_HIV',
       'winsorized_GDP', 'winsorized_Population',
       'winsorized_thinness_1to19_years', 'winsorized_thinness_5to9_years',
       'winsorized_Income_Comp_Of_Resources', 'winsorized_Schooling',
       'winsorized_Measles', 'Developing']]

from sklearn.preprocessing import LabelEncoder, OneHotEncoder
labelencoder=LabelEncoder()
X.iloc[:,0]=labelencoder.fit_transform(X.iloc[:,0])
onehotencoder = OneHotEncoder()
X = onehotencoder.fit_transform(X).toarray()

Y = life['winsorized_Life_Expectancy']

from sklearn.model_selection import train_test_split
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.3, random_state= 42)

from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score, mean_squared_error, mean_absolute_error
model = LinearRegression(fit_intercept=True, normalize=True).fit(X_train, Y_train)
predictions= model.predict(X_test)

len(predictions)

r2_score(predictions, Y_test)
mean_squared_error(predictions, Y_test)

