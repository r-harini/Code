# https://www.kaggle.com/micahshull/r-airbnb-tree-forest-svm-regression

library(leaps)
library(caret)
library(dplyr)
library(tidyverse)
library(lattice)
library(e1071)
library(caTools)


data=read.csv("AB_NYC_2019.csv")
df <- data %>% select(price, # place target variable first
                    #id,
                    #name,                          
                    #host_id,
                    #host_name,
                    neighbourhood_group,
                    #neighbourhood,                 
                    latitude, 
                    longitude,                     
                    room_type,                                               
                    minimum_nights, 
                    number_of_reviews,             
                    #last_review, 
                    reviews_per_month,             
                    calculated_host_listings_count,
                    availability_365)

df$reviews_per_month[is.na(df$reviews_per_month)] <- 0
columns <- c("neighbourhood_group","room_type")
df[, columns] <- df %>% select(all_of(columns)) %>% lapply(as.factor)
df%>%glimpse()

# Outlier Detection and Removal
skewness(df$price) # > 1 = highly skewed towards the right
# data with outliers removed
a <- df %>% filter(price < 1000)
skewness(a$price) # > 1 but much less skewed than before
Q <- quantile(df$price, probs=c(.25, .75), na.rm = T)
iqr <- IQR(df$price, na.rm = T)
df2 <- df %>% filter(price > (Q[1] - 1.5*iqr) & 
                       price < (Q[2] + 1.5*iqr))  


# Perform ANOVA etc




# change all data types to numeric
c1 <- df2
cols = c("neighbourhood_group", "room_type")
c1[,cols] <- c1 %>% select_if(is.factor) %>% lapply(as.numeric)

# Step 1) Dropping response variable (Y)
m <- subset(c1, select = -c(price))
mc <- cor(m)
# Checking Variables that are highly correlated
highlyCorrelated = findCorrelation(mc, cutoff=0.7)
highlyCorCol = colnames(m)[highlyCorrelated]
highlyCorCol

set.seed(123)
split = sample.split(df2$price, SplitRatio = 0.75)
training_set = subset(df2, split == TRUE)
test_set = subset(df2, split == FALSE)

# backward elimination
fit1=lm(price~., data=c1)
step(fit1, direction="backward")
library(SignifReg)
SignifReg(fit1, scope=training_set,criterion="p-value", direction="backward",alpha=0.05)


#Model 1 (including outliers)
m1 <- training_set %>% select(price, # place target variable first
                              neighbourhood_group,
                              latitude, 
                              longitude,                     
                              room_type,                                               
                              minimum_nights, 
                              number_of_reviews,             
                              #reviews_per_month,             
                              calculated_host_listings_count,
                              availability_365
) %>% lm()  
summary(m1)

n = ncol(training_set)
fit <- regsubsets(price ~ ., data = training_set, nvmax = n)
sfit <- summary(fit)

# best model has the largest adjutsed R-Squred
which.max(sfit$adjr2) # now print the coefficients of the model
coef(fit, which.max(sfit$adjr2))
# these are the coefficients for the best fitting model
m2 <- lm(price ~
           neighbourhood_group +
           latitude +
           longitude +
           room_type +
           minimum_nights +
           availability_365,
         data = training_set)
summary(m2)


# Interaction Terms
m3 <- lm(price ~
           #neighbourhood_group +
           #latitude +
           #longitude +
           room_type +
           minimum_nights +
           availability_365 + 
           #neighbourhood_group * longitude +
           neighbourhood_group * latitude + 
           #neighbourhood_group * number_of_reviews + 
           #neighbourhood_group * availability_365 +
           room_type * longitude,
         #room_type * latitude + 
         #room_type * number_of_reviews,
         #room_type * availability_365,
         data = training_set)
summary(m3)


# Model Comparison
cat("#####   Model Comparison   #####\n");
cat("\nModel 1 R-Squared = ", round(as.numeric(summary(m1)[9]),4));
cat("\nModel 2 R-Squared = ", round(as.numeric(summary(m2)[9]),4));
cat("\nModel 3 R-Squared = ", round(as.numeric(summary(m3)[9]),4))

# Fitting Decision Tree Regression to the dataset
library(rpart)
m4 = rpart(formula = price ~ .,
           data = training_set,
           method = "anova")
printcp(m4)
caret::varImp(m4)
library(rpart.plot)
rpart.plot(m4)
# Random Forest Regression
library(randomForest)
set.seed(1234)
m6 = rpart(formula = price ~ .,
           data = training_set,
           method = "anova")
printcp(m6)
caret::varImp(m6)

# Support Vector Machine
#### Takes a bit of time #### (15min)
m7 = svm(formula = price ~ .,
         data = training_set,
         type = 'eps-regression',
         kernel = 'radial',
         gamma = 0.5,
         cost = 4)
summary(m7)

# Prediction
y_pred1 = predict(m1, newdata = test_set)
y_pred2 = predict(m2, newdata = test_set) 
y_pred3 = predict(m3, newdata = test_set)
y_pred4 = predict(m4, newdata = test_set) 
y_pred6 = predict(m6, newdata = test_set)
y_pred7 = predict(m7, newdata = test_set)

# Accuracy 
#------ model 1  --------
MSE1 = sum((y_pred1 - test_set$price)^2)/nrow(test_set)
var.y1 = sum((test_set$price - mean(test_set$price))^2)/(nrow(test_set)-1)
Rsqr1 = 1 - (MSE1/var.y1)

#------ model 2  --------
MSE2 = sum((y_pred2 - test_set$price)^2)/nrow(test_set)
var.y2 = sum((test_set$price - mean(test_set$price))^2)/(nrow(test_set)-1)
Rsqr2 = 1 - (MSE2/var.y2)

#------ model 3  --------
MSE3 = sum((y_pred3 - test_set$price)^2)/nrow(test_set)
var.y3 = sum((test_set$price - mean(test_set$price))^2)/(nrow(test_set)-1)
Rsqr3 = 1 - (MSE3/var.y3)

#------ model 4  --------
MSE4 = sum((y_pred4 - test_set$price)^2)/nrow(test_set)
var.y4 = sum((test_set$price - mean(test_set$price))^2)/(nrow(test_set)-1)
Rsqr4 = 1 - (MSE4/var.y4)

#------ model 6  --------
MSE6 = sum((y_pred6 - test_set$price)^2)/nrow(test_set)
var.y6 = sum((test_set$price - mean(test_set$price))^2)/(nrow(test_set)-1)
Rsqr6 = 1 - (MSE6/var.y6)

#------ model 7  --------
MSE7 = sum((y_pred7 - test_set$price)^2)/nrow(test_set)
var.y7 = sum((test_set$price - mean(test_set$price))^2)/(nrow(test_set)-1)
Rsqr7 = 1 - (MSE7/var.y7)

cat("#####     Compare Model Accuracy     #####\n")
cat("\nMSE Model 1 = ", MSE1, " Variance  = ", var.y1, "R Squared = ", Rsqr1);
cat("\nMSE Model 2 = ", MSE2, " Variance  = ", var.y2, "R Squared = ", Rsqr2);
cat("\nMSE Model 3 = ", MSE3, " Variance  = ", var.y3, "R Squared = ", Rsqr3);
cat("\nMSE Model 4 = ", MSE4, " Variance  = ", var.y4, "R Squared = ", Rsqr4);
cat("\nMSE Model 6 = ", MSE6, " Variance  = ", var.y6, "R Squared = ", Rsqr6);
cat("\nMSE Model 7 = ", MSE7, " Variance  = ", var.y7, "R Squared = ", Rsqr7)
