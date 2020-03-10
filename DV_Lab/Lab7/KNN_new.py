# -*- coding: utf-8 -*-
"""
Created on Mon Feb 17 18:21:07 2020

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
df=load_breast_cancer()


array=df.values
df.head()
X=array[:,1:33]
y=array[:,[0]]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)
X_train.shape,X_test.shape
clf=KNeighborsClassifier(n_neighbors=3) 
clf.fit(X_train,y_train)
acc_train = clf.score(X_train, y_train)
print('Train set accuracy: ', acc_train)
acc_train = clf.score(X_test, y_test)
print('Train set accuracy: ', acc_train)
training_accuracy =[]
testing_accuracy = []
neighbors_settings = range(1, 10)
for n_neighbors in neighbors_settings: 
    clf = KNeighborsClassifier(n_neighbors=n_neighbors)
    clf.fit(X_train, y_train)
    training_accuracy.append(clf.score(X_train, y_train))
    testing_accuracy.append(clf.score(X_test, y_test))
plt.plot(neighbors_settings, training_accuracy, label="training accuracy")
plt.plot(neighbors_settings, testing_accuracy, label="test accuracy")
plt.ylabel("Accuracy")
plt.xlabel("n_neighbors")
plt.legend()
plt.show()
