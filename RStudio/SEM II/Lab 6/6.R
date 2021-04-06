rm(list=ls())

setwd("C:/Code/RStudio/SEM II/Lab 6")


library(dplyr)
library(class)
library(caret)

data <- read.csv("Parkinsons.csv",stringsAsFactors = T)

data[,-4] <- scale(data[,-4])

#75-25
data_TRAIN <-sample_n(data,146)
data_TEST <-setdiff(data,data_TRAIN)

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=3)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=5)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=7)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=9)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=11)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=13)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=15)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=17)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=19)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=21)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=23)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=25)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

#50-50
data_TRAIN <-sample_n(data,97)
data_TEST <-setdiff(data,data_TRAIN)

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=3)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=7)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=9)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=11)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=13)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=15)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=17)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=19)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=21)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=23)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')

knnpredict <- knn(train=data_TRAIN[,-4],test=data_TEST[,-4],cl=data_TRAIN$status, k=25)
confusionMatrix(table(knnpredict,data_TEST$status),positive='1')
