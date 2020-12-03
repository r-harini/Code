data=read.csv("Train.csv")
str(data)
data$ClassId=as.factor(data$ClassId)
res=aov(Height~ClassId,data)
summary.aov(res)

library(car)
leveneTest(Height~ClassId,data)
