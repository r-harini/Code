rm(list=ls())
library(datarium)
data("marketing")
str(marketing)
head(marketing)

#suppose we want to predict future sales
#based on the advertising budget spent on youtube

#visualization
library(ggplot2)
ggplot(marketing,aes(x=youtube,y=sales))+geom_point()
ggplot(marketing,aes(x=youtube,y=sales))+geom_point()+geom_smooth()
ggplot(marketing,aes(x=youtube,y=sales))+geom_point()+geom_smooth(method='lm',se=FALSE)

#finding correlation
cor(marketing$youtube,marketing$sales)

#building a linear model
model <- lm(sales~youtube,data=marketing)
model
#estimated regression line equation:sales = 8.44+0.048*youtube

#model summary
summary(model)

#confidence interval
confint(model)

#RSE
sigma(model)*100/mean(marketing$sales)
