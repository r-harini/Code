rm(list=ls())

#1
install.packages("MASS")

#2
library(MASS)

#3
df=na.omit(survey)
str(df)

#4
class(df)
typeof(df)

#5
nrow(df)
ncol(df)

#6
dim(df)

#7
summary(df)

#8
colnames(df)

#9
head(df,3)

#10
tail(df,2)


