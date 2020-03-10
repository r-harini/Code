# -*- coding: utf-8 -*-
"""
Created on Sun Feb 23 22:50:05 2020

@author: rhari
"""

import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import RepeatedKFold
import re

data=pd.read_csv('train.csv')
test=pd.read_csv('test.csv')
data.head()
data.describe()

data.isnull().sum() #null values
null_values=data.isnull().sum().sort_values(ascending=False)
null_values.plot.bar()

#Visualising the dataset
sns.countplot(data['Survived'])
sns.catplot(x='Sex', y='Survived' , data=data, kind='bar')
data.groupby(['Pclass', 'Survived'])['Survived'].count()
sns.countplot(x='Sex', hue='Survived', data=data)

def age_nan(df):
    for i in df.Sex.unique():
        for j in df.Pclass.unique():
            x=df.loc[((df.Sex==i) & (df.Pclass==j)),'Age'].mean()
            df.loc[((df.Sex==i) & (df.Pclass==j)), 'Age']=df.loc[((df.Sex==i) & (df.Pclass==j)), 'Age'].fillna(x)

age_nan(data)
age_nan(test)

data['Embarked']=data['Embarked'].fillna('S')
test['Embarked']=test['Embarked'].fillna('S')

data['Cabin_NaN']=data['Cabin'].isnull().astype(int)
test['Cabin_NaN']=test['Cabin'].isnull().astype(int)

test.Fare=test.Fare.fillna(-1)

def reg_cross_val(variables):
    X=data[variables]
    y=data['Survived']
    rkfold=RepeatedKFold(n_splits=2, n_repeats=10, random_state=10)
    result=[]
    for treino, teste in rkfold.split(X):
        X_train, X_test=X.iloc[treino], X.iloc[teste]
        y_train, y_test= y.iloc[treino], y.iloc[teste]
        reg=LogisticRegression(max_iter=500)
        reg.fit(X_train, y_train)
        result.append(reg.score(X_test, y_test))
    return np.mean(result)

"""def is_female(x):
    if x=='female':
         return 1
     else:
         return 0

data['Sex_bin']=data['Sex'].map(is_female)
test['Sex_bin']=test['Sex'].map(is_female)
"""

from sklearn.preprocessing import LabelEncoder
number1=LabelEncoder()
data['Sex_bin']=number1.fit_transform(data['Sex'].astype('str'))
test['Sex_bin']=number1.transform(test['Sex'].astype('str'))

number2=LabelEncoder()
data['Embarked_S']=number2.fit_transform(data['Embarked'].astype('str'))
test['Embarked_S']=number2.transform(test['Embarked'].astype('str'))

variables_before=['Age', 'Pclass', 'Fare', 'SibSp', 'Parch']
print('Before the new features:', reg_cross_val(variables_before))

variables=['Age', 'Sex_bin' , 'Pclass', 'Fare', 'SibSp', 'Parch', 'Embarked_S', 'Cabin_NaN']
print('With the new features:', reg_cross_val(variables))

data['Family']=data.SibSp + data.Parch
test['Family']=test.SibSp + test.Parch

variables=['Age', 'Sex_bin', 'Pclass', 'Fare', 'Embarked_S', 'Cabin_NaN', 'Family']
reg_cross_val(variables)

text_ticket=''
for i in data.Ticket:
    text_ticket+=i

lista=re.findall('[a-zA-Z]+', text_ticket)
print('Most repeated terms in Tickets: \n')
print(pd.Series(lista).value_counts().head(10))
a=pd.Series(lista).value_counts().head(10)

from sklearn.feature_extraction.text import TfidfVectorizer
tv=TfidfVectorizer()
X_name=tv.fit_transform(data['Name'])

data['CA']=data['Ticket'].str.contains('CA|C.A.').astype(int)
data['SOTON']=data['Ticket'].str.contains('SOTON|STON').astype(int)
data['PC']=data['Ticket'].str.contains('PC').astype(int)
data['SC']=data['Ticket'].str.contains('SC|S.C').astype(int)
data['C']=data['Ticket'].str.contains('C').astype(int)

test['CA']=test['Ticket'].str.contains('CA|C.A.').astype(int)
test ['SOTON']=test['Ticket'].str.contains('SOTON|STON').astype(int)
test['PC']=test['Ticket'].str.contains('PC').astype(int)
test['SC']=test['Ticket'].str.contains('SC|S.C').astype(int)
test['C']=test['Ticket'].str.contains('C').astype(int)

text_name=''
for i in data.Name:
    text_name+=i

lista=re.findall('[a-zA-Z]+', text_name)
print("Most repeated words in Name Column: \n")
print(pd.Series(lista).value_counts().head(10))

data['Mr']=data['Name'].str.contains('Mr').astype(int)
data['Master']=data['Name'].str.contains('Master').astype(int)
data['Miss']=data['Name'].str.contains('Miss').astype(int)
data['Mrs']=data['Name'].str.contains('Mrs').astype(int)

test['Mr']=test['Name'].str.contains('Mr').astype(int)
test['Master']=test['Name'].str.contains('Master').astype(int)
test['Miss']=test['Name'].str.contains('Miss').astype(int)
test['Mrs']=test['Name'].str.contains('Mrs').astype(int)


variables=['Age', 'Pclass', 'SibSp', 'Parch','Fare', 'Cabin_NaN', 'Sex_bin', 'Embarked_S', 'Family', 'CA', 'SOTON', 'PC', 'SC','C', 'Mr', 'Miss', 'Master', 'Mrs', 'Family']
print(reg_cross_val(variables))

X=data[variables]
y=data['Survived']
reg=LogisticRegression(max_iter=500)
reg.fit(X,y)
y_pred=reg.predict(test[variables])

submit=pd.Series(y_pred, index=test['PassengerId'], name='Survived')
submit.to_csv('Predicted.csv', header=True)
