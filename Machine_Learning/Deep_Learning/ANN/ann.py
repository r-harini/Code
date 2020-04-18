#Data Preprocessing

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

dataset=pd.read_csv("Churn_Modelling.csv")
X=dataset.iloc[:,3:13].values
y=dataset.iloc[:,13].values

#Encoding the categorical variables
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
labelencoder_X_1=LabelEncoder()
X[:,1]=labelencoder_X_1.fit_transform(X[:,1])
labelencoder_X_2=LabelEncoder()
X[:,2]=labelencoder_X_2.fit_transform(X[:,2])
onehotencoder=OneHotEncoder(categorical_features=[1])
X=onehotencoder.fit_transform(X).toarray()
X=X[:,1:]

#Splitting the dataset
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test=train_test_split(X,y, test_size=0.25,  random_state=0)

#Feature Scaling
from sklearn.preprocessing import StandardScaler
sc=StandardScaler()
X_train=sc.fit_transform(X_train)
X_test=sc.transform(X_test)

#Making the ANN
import keras
from keras.models import Sequential  #Used to intialise the Neural network
from keras.layers import Dense      #Model used to make the layers
 
neural_network=Sequential()

#Adding the input and the hidden layer
neural_network.add(Dense(units=6, kernel_initializer="uniform" , activation="relu",input_dim=11))

#Adding the second hidden layer
neural_network.add(Dense(units=6, kernel_initializer="uniform", activation="relu"))

#Adding the output layer
neural_network.add(Dense(units=1, kernel_initializer="uniform", activation="sigmoid"))

#Compiling the ANN
neural_network.compile(optimizer="adam", loss="binary_crossentropy", metrics=['accuracy'])

#Fitting the ANN to the training set
neural_network.fit(X_train, y_train, batch_size=10, nb_epoch=100)

#Predicting
y_pred=neural_network.predict(X_test)
y_pred= (y_pred>0.5)

#Making the confusion matrix
from sklearn.metrics import confusion_matrix
cm=confusion_matrix(y_test, y_pred)
