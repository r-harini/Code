# -*- coding: utf-8 -*-
"""
Created on Tue Feb 11 16:48:41 2020

@author: rhari
"""

import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.datasets.samples_generator import make_blobs
from sklearn.cluster import KMeans

d=pd.read_csv('protein.csv')
data=d.iloc[:,1:].values
X,y=make_blobs(n_samples=300, centers=4, cluster_std=0.6, random_state=0)
plt.scatter(X[:,0], X[:,1])

plt.scatter(data[:,0], data[:,1])
wcss=[]
for i in range(1,11):
    kmeans=KMeans(n_clusters=i, init='k-means++', max_iter=300, n_init=10, random_state=0)
    kmeans.fit(data)
    wcss.append(kmeans.inertia_)
plt.plot(range(1,11), wcss)
plt.title('Elbow method')
plt.xlabel('Number of clusters')
plt.ylabel('WCSS')
plt.show()



kmeans=KMeans(n_clusters=2, init='k-means++', max_iter=300, n_init=10, random_state=0)
pred_y=kmeans.fit_predict(data)
plt.scatter(data[:,0],data[:,1])
plt.scatter(kmeans.cluster_centers_[:,0], kmeans.cluster_centers_[:,1], s=300,c='red')
plt.show()
