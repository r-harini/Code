import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

diabetes=pd.read_csv('Diabetes.csv')

data=diabetes
diabetes.columns
diabetes.head
feature_names=['Pregnancies','Glucose','BloodPressure','SkinThickness','Insulin','BMI','DiabetesPedigreeFunction','Age']
X=diabetes[feature_names]
y=diabetes.Outcome

print("Diabetes data set dimensions:{}".format(diabetes.shape))

#Visualising the dataset
corr=diabetes.corr()
sns.heatmap(corr, xticklabels=corr.columns, yticklabels=corr.columns)

sns.FacetGrid(data, hue="Outcome", size=4).map(plt.scatter, "Age", "Pregnancies").add_legend()

plt.bar(data['Outcome'], data['Pregnancies'])
plt.xlabel('Outcome')
plt.ylabel('Pregnancies')
plt.show()

diabetes.groupby('Outcome').size()
diabetes.hist(bins=50, figsize=(20,15))
plt.show()

sns.countplot(x=diabetes['Age'])
sns.countplot(x=diabetes['Age'], hue=diabetes['Outcome'])
sns.countplot(data['Outcome'])

plt.scatter(data['Age'], data['BMI'])
plt.xlabel('Age')
plt.ylabel('BMI')
plt.show()

    
#Data cleaning
t=diabetes.describe()

median_bmi=diabetes['BMI'].median()
diabetes['BMI']=diabetes['BMI'].replace(to_replace=0, value=median_bmi)

median_bloodp=diabetes['BloodPressure'].median()
diabetes['BloodPressure']=diabetes['BloodPressure'].replace(to_replace=0, value=median_bloodp)

median_gluc=diabetes['Glucose'].median()
diabetes['Glucose']=diabetes['Glucose'].replace(to_replace=0, value=median_gluc)

median_skin=diabetes['SkinThickness'].median()
diabetes['SkinThickness']=diabetes['SkinThickness'].replace(to_replace=0, value=median_skin)

median_ins=diabetes['Insulin'].median()
diabetes['Insulin']=diabetes['Insulin'].replace(to_replace=0, value=median_ins)


#Feature selection
from sklearn.feature_selection import SelectKBest, chi2
feature_ranking=SelectKBest(chi2, k=5)
fit=feature_ranking.fit(X,y)
fmt = '%-8s%-20s%s'

print(fmt % ('', 'Scores', 'Features'))
for i, (score, feature) in enumerate(zip(feature_ranking.scores_, X.columns)):
    print(fmt % (i, score, feature))
    
plt.bar(feature_names ,feature_ranking.scores_)
plt.xlabel('Features', color='red')
plt.ylabel('Feature Score', color='red')
plt.show()


#Splitting
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test= train_test_split(X,y, stratify=diabetes.Outcome, random_state=0)
names=[]
scores=[]

#Model Selection
from sklearn.model_selection import cross_val_score
from sklearn.metrics import accuracy_score

#Applying K-Nearest Neighbors Model
from sklearn.neighbors import KNeighborsClassifier
classifier1=KNeighborsClassifier()
classifier1.fit(X_train, y_train)
y_pred=classifier1.predict(X_test)

scores.append(accuracy_score(y_test, y_pred))
names.append("K-Nearest Neighbor")

#Applying Decision Tree Model
from sklearn.tree import DecisionTreeClassifier
classifier4=DecisionTreeClassifier(random_state=0)
classifier4.fit(X_train, y_train)
y_pred=classifier4.predict(X_test)
scores.append(accuracy_score(y_test, y_pred))
names.append('Decision Tree')

#Applying Naive Bayes Model
from sklearn.naive_bayes import GaussianNB
classifier2=GaussianNB()
classifier2.fit(X_train,y_train)
y_pred=classifier2.predict(X_test)

scores.append(accuracy_score(y_test,y_pred))
names.append("Naive Bayes")

#Applying Logistic Regression Model
from sklearn.linear_model import LogisticRegression
classifier3=LogisticRegression()
classifier3.fit(X_train, y_train)
y_pred=classifier3.predict(X_test)

scores.append(accuracy_score(y_test, y_pred))
names.append("Logistic Regression")

#Applying Random Forest Model
from sklearn.ensemble import RandomForestClassifier
rf=RandomForestClassifier(n_estimators=100, random_state=0)
rf.fit(X_train, y_train)
y_pred=rf.predict(X_test)
scores.append(accuracy_score(y_test, y_pred))
names.append('Random Forest')

Final=pd.DataFrame({'Name':names,'Score':scores})
print(Final)


