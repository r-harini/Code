# -*- coding: utf-8 -*-
"""
Created on Tue Feb 11 16:18:11 2020

@author: rhari
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import mglearn

from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics

from sklearn.datasets import load_breast_cancer
cancer=load_breast_cancer()
cancer.keys()
cancer.data.shape
X=cancer.data
y=cancer.target
print("Sample counts for class:\n{}".format({n: v for n, v in zip(cancer.target_names, np.bincount(cancer.target))})) 

X_train, X_test, y_train, y_test= train_test_split(X,y, random_state=0)

clf=KNeighborsClassifier(n_neighbors=3)
clf.fit(X_train, y_train)

acc_train=clf.score(X_train, y_train)
print("Train set accuracy:", acc_train)

acc_test=clf.score(X_test, y_test)
print("Test set accuracy:", acc_test)

y_pred=clf.predict(X_test)

from sklearn.metrics import confusion_matrix
from sklearn.metrics import f1_score
from sklearn.metrics import accuracy_score
cm=confusion_matrix(y_test, y_pred)
print(f1_score(y_test, y_pred))
print(accuracy_score(y_test, y_pred))


#Using Naive Bayes Algorithm
from sklearn.naive_bayes import GaussianNB
classifier2=GaussianNB()
classifier2.fit(X_train,y_train)
y_pred=classifier2.predict(X_test)
print(accuracy_score(y_test, y_pred))

#Using Logistic Regression
from sklearn.linear_model import LogisticRegression
classifier3=LogisticRegression()
classifier3.fit(X_train, y_train)
y_pred=classifier3.predict(X_test)
print(accuracy_score(y_test, y_pred))

