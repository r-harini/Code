rm(list=ls())

setwd("C:/Code/RStudio/SEM II/Lab 5")

data=read.csv("crashTest_TRAIN.csv", stringsAsFactors = T)

logreg <- glm(formula = data$CarType ~.,family='binomial', data = data) 

summary(logreg) 

logitrain <- predict(logreg, type='response') # type='response' gives probability otherwise the log-odds by default 

plot(logitrain) 

tapply(logitrain,data$CarType,mean) 

TEST_data <- read.csv("crashTest_TEST.csv",stringsAsFactors = T) 

logitest <- predict(logreg, newdata = TEST_data, type='response') 

plot(logitest) 

tapply(logitest,TEST_data$CarType,mean) 

TEST_data[logitest <=0.98, "LogiTest"]="Hatchback" 

TEST_data[logitest >0.98, "LogiTest"]="SUV" 

# install.packages("caret") 

library(caret) 

confusionMatrix(table(TEST_data[,7],TEST_data[,8]),positive='SUV') 

