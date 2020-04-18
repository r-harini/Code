#Importing the dataset
dataset=read.csv("Position_Salaries.csv")
dataset=dataset[, 2:3]

#Training and test set split
# library(caTools)
# set.seed(123)
# split=sample.split(dataset$Salary, SplitRatio = 0.8)
# training_set=subset(dataset, split==TRUE)
# test_set=subset(dataset, split==FALSE)

#Linear Regression
lin_reg=lm(formula = Salary~., data= dataset)

#Polynomial Regression
dataset$Level2=dataset$Level^2
dataset$Level3=dataset$Level^3
dataset$Level4=dataset$Level^4
dataset$Level5=dataset$Level^5
poly_reg=lm(formula = Salary~., data=dataset)

#Visualising
library(ggplot2)
ggplot()+
  geom_point(aes(x=dataset$Level, y=dataset$Salary), colour="red")+
  geom_line(aes(x=dataset$Level, y=predict(poly_reg, newdata = dataset)), colour="blue")
