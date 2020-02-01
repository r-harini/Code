# -*- coding: utf-8 -*-
"""
Created on Fri Dec 27 19:24:49 2019

@author: rhari
"""

import numpy as np
import pandas as pd

dataset=pd. read_csv('heart.csv')
X=dataset.iloc[:,:-1].values
y=dataset.iloc[:,-1].values

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test=train_test_split(X, y, test_size=0.2)

#Model Selection
from sklearn.model_selection import cross_val_score
from sklearn.metrics import accuracy_score

#Logistic regression
from sklearn.linear_model import LogisticRegression
classifier2=LogisticRegression()
classifier2.fit(X_train, y_train)
y_pred=classifier2.predict(X_test)
name2="Logistic Regression"
"""print(name2)
print(accuracy_score(y_test, y_pred))


new=[[57,0,0,120,354,0,1,163,1,0.6,2,0,2]]
y_pred=classifier2.predict(new)
print(y_pred)"""

#k=np.array([['51','1','2']])
#k=k.astype(np.float)

from flask import Flask, render_template, request
model=Flask(__name__)

@model.route('/')
def index():
    return render_template('index.html')

@model.route('/', methods=['POST'])
def getvalue():
    age=request.form['age']
    sex=request.form['sex']
    cp=request.form['cp']
    trestbps=request.form['trestbps']
    chol=request.form['chol']
    fbs=request.form['fbs']
    restecg=request.form['restecg']
    thalach=request.form['thalach']
    exang=request.form['exang']
    oldpeak=request.form['oldpeak']
    slope=request.form['slope']
    ca=request.form['ca']
    thal=request.form['thal']
    new1=np.array([[age,sex,cp,trestbps,chol,fbs,restecg,thalach,exang,oldpeak,slope,ca,thal]])
    new1=new1.astype(np.float)
    pred=classifier2.predict(new1)
    if (pred==1):
        value="Yes"
    return render_template('index.html', val=value)
    #print(pred)

if __name__=='__main__':
    model.run(debug=True)