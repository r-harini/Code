#Apriori

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#Importing the Dataset
dataset=pd.read_csv('Market_Basket_Optimisation.csv', header=None)
transactions=[]
for i in range(0,7501):
    transactions.append([str(dataset.values[i,j]) for j in range(0,20)])
    
#Training Apriori on the dataset
from apyori import apriori
rules=apriori(transactions, min_support=0.003, min_confidence=0.2,min_lift=3, min_length=2)

#visualising the results
results=list(rules)

listed_rules=[]
for i in range(0, len(results)):
    if 'nan' in (str(list(results[i][0])[0]) + str(list(results[i][0])[1])):
        pass
    else:
        listed_rules.append('Rule: ' + str(list(results[i][0])[0]) +
                        ' -> ' + str(list(results[i][0])[1]) +
                        ' \nS: ' + str(round(results[i].support, 4)) +
                        ' \nC: ' + str(round(results[i][2][0].confidence, 4)) +
                        ' \nL: ' + str(round(results[i][2][0].lift, 4)))
