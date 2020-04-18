dataset=read.csv("Social_Network_Ads.csv")
dataset=dataset[,3:5]

# #Categorical data
# dataset$Gender=factor(dataset$Gender, 
#                levels = c('Male', 'Female'), 
#                labels = c(0,1))

#Splitting the dataset
library(caTools)
set.seed(123)
split=sample.split(dataset$Purchased, SplitRatio = 0.75)
training_set=subset(dataset, split==TRUE)
test_set=subset(dataset,split==FALSE)

#Feature Scaling
training_set[, 1:2]=scale(training_set[, 1:2])
test_set[,1:2]=scale(test_set[, 1:2])

#Fitting Logistic Regression to the Training Set
classifier=glm(formula = Purchased~., family = binomial ,data=training_set)
summary(classifier)

prob_pred=predict(classifier, type="response",newdata=test_set[-3])
