# -*- coding: utf-8 -*-
"""
Created on Sun May 17 17:36:42 2020

@author: rhari
"""

import numpy as np
import pandas as pd
dataset=pd.read_csv("diab.csv")

dataset["33.6"].isin([0]).sum()

dataset[4]
