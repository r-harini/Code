# -*- coding: utf-8 -*-
"""
Created on Sun Dec 15 11:44:20 2019

@author: rhari
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

dataset=pd.read_csv("Position_Salaries.csv")
X=dataset.iloc[:,1:2].values
y=dataset.iloc[:,2].values

from sklearn.svm import SVR