
library(tidyverse)
library(caret)
library(MASS)
#loading Boston housing data in MASS for predicting median house value
data('Boston')
str(Boston)

#split the data into training and test data set
set.seed(123)
train_samples <- Boston$medv %>%
  createDataPartition(p=0.8,list=FALSE)
#head(train_samples)
train <- Boston[train_samples,]
test <- Boston[-train_samples,]

#Building a regression model
model <- lm(medv~.,data=train)

#Make predictions
pred <- model %>%
  predict(test)

#model performance
RMSE <- RMSE(pred,test$medv)
RMSE

R2 <- R2(pred,test$medv)
R2

#Detecting multicollinearity
library(car)
vif(model)


#Dealing with multicollinearity
#Building a model excluding those variables
model2 <- lm(medv~.-tax,data=train)
pred2 <- model2%>%
  predict(test)
data.frame(
  RMSE <- RMSE(pred2,test$medv),
  R2 <- R2(pred2,test$medv)
)


model3 <- lm(medv~.-rad,-tax,data=train)
pred2 <- model3%>%
  predict(test)
data.frame(
  RMSE <- RMSE(pred2,test$medv),
  R2 <- R2(pred2,test$medv)
)

par(mar=c(2,2,2,2))
par(mfrow=c(2,2))
plot(model)

#-------------------
library(datarium)
data("marketing")
str(marketing)
head(marketing)

#building a linear model
model <- lm(sales~youtube,data=marketing)
model

plot(model,1)
plot(model,2)
plot(model,3)
plot(model,5)

model2 <- lm(log(sales)~youtube,data=marketing)
plot(model2,3)
