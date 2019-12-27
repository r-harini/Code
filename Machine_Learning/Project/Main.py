# -*- coding: utf-8 -*-
"""
Created on Fri Dec  6 19:11:40 2019

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

#Splitting
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test= train_test_split(X,y, stratify=diabetes.Outcome, random_state=0)
train_test_split()
names=[]
scores=[]

#Model Selection
from sklearn.model_selection import cross_val_score
from sklearn.metrics import accuracy_score

#Applying K-Nearest Neighbors Model
from sklearn.neighbors import KNeighborsClassifier
classifier1=KNeighborsClassifier()
classifier1.fit(X_train, y_train)
y_pred=classifier1.predict(X_test)

from sklearn.metrics import confusion_matrix
from sklearn.metrics import f1_score
conf_matrix = confusion_matrix(y_test,y_pred)
print(conf_matrix)
print(f1_score(y_test,y_pred))

scores.append(accuracy_score(y_test, y_pred))
names.append("K-Nearest Neighbor")

#Applying Naive Bayes Model
from sklearn.naive_bayes import GaussianNB
classifier2=GaussianNB()
classifier2.fit(X_train,y_train)
y_pred=classifier2.predict(X_test)

scores.append(accuracy_score(y_test,y_pred))
names.append("Naive Bayes")

#Applying Logistic Regression Model
from sklearn.linear_model import LogisticRegression
classifier3=LogisticRegression()
classifier3.fit(X_train, y_train)
y_pred=classifier3.predict(X_test)

scores.append(accuracy_score(y_test, y_pred))
names.append("Logistic Regression")

Final=pd.DataFrame({'Name':names,'Score':scores})
print(Final)

axis=sns.barplot(x='Name', y='Score', data=Final)
axis.set(xlabel='Model',ylabel='Accuracy')

for p in axis.patches:
    height=p.get_height()
    axis.text(p.get_x()+p.get_width()/2,height+0.005,'{:1.4f}'.format(height), ha="center")
plt.show()