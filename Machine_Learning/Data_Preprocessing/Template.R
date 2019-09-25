#Importing Dataset
dataset=read.csv('Data.csv')
#dataset=dataset[,2:3]

#Splitting dataset into trainng and test set
#install.packages('caTools')
#Click the checkbox of caTools OR 
library(caTools)
set.seed(123)
split=sample.split(dataset$Purchased, SplitRatio=0.8, )
training_set=subset(dataset,split==TRUE)
test_set=subset(dataset, split==FALSE)

#Feature Scaling
#training_set[,2:3]=scale(training_set[, 2:3])
#test_set[, 2:3]=scale(test_set[, 2:3])