# -*- coding: utf-8 -*-
"""
Created on Mon Dec  9 21:39:55 2019

@author: rhari
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

diabetes=pd.read_csv('Diabetes.csv')
diabetes.columns
diabetes.head

print("Diabetes data set dimensions:{}".format(diabetes.shape))

#Visualising the dataset
diabetes.groupby('Outcome').size()
diabetes.hist(bins=50, figsize=(20,15))
plt.show()
#Data cleaning
diabetes.isnull().sum()
diabetes.isna().sum()

median_bmi=diabetes['BMI'].median()
diabetes['BMI']=diabetes['BMI'].replace(to_replace=0, value=median_bmi)

median_bloodp=diabetes['BloodPressure'].median()
diabetes['BloodPressure']=diabetes['BloodPressure'].replace(to_replace=0, value=median_bloodp)

median_gluc=diabetes['Glucose'].median()
diabetes['Glucose']=diabetes['Glucose'].replace(to_replace=0, value=median_gluc)

median_skin=diabetes['SkinThickness'].median()
diabetes['SkinThickness']=diabetes['SkinThickness'].replace(to_replace=0, value=median_skin)

median_ins=diabetes['Insulin'].median()
diabetes['Insulin']=diabetes['Insulin'].replace(to_replace=0, value=median_ins)


feature_names=['Pregnancies','Glucose','BloodPressure','SkinThickness','Insulin','BMI','DiabetesPedigreeFunction','Age']
X=diabetes[feature_names]
y=diabetes.Outcome