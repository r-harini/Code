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

diabetes.groupby('Outcome').size()
diabetes.groupby('Outcome').hist(figsize=(9,9))

