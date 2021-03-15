rm(list=ls())
library(dplyr)

df=read.csv("CreditWorthiness.csv")

#Using Camt and Cpur variables
data=df%>%
  dplyr::select(Camt,Cpur)

group_by(data, Cpur)%>%summarise(count=n(), mean=mean(Camt, na.rm=TRUE))

#ANOVA
result=aov(Camt~Cpur, data=data)
summary(result)

TukeyHSD(result)

#Homogeneity of variances (equal variances assumption)
plot(result, 1)

#Normality assumption
plot(result,2)

#Shapiro Wilk Test
res=residuals(result)
shapiro.test(res)

# Kruskal-Wallis rank sum test (used when ANOVA assumptions are not met)
kruskal.test(Cpur~Camt, data=data)

# Using Camt and Job Type
data=df%>%
  dplyr::select(Camt, JobType)

group_by(data, JobType)%>%summarise(count=n(), mean=mean(Camt, na.rm=TRUE))

#ANOVA
result=aov(Camt~JobType, data=data)
summary(result)

TukeyHSD(result)

#Homogeneity of variances (equal variances assumption)
plot(result, 1)

#Normality assumption
plot(result,2)

#Shapiro Wilk Test
res=residuals(result)
shapiro.test(res)

# Kruskal-Wallis rank sum test (used when ANOVA assumptions are not met)
kruskal.test(JobType~Camt, data=data)

# Using Camt and Htype
data=df%>%
  dplyr::select(Camt, Htype)

group_by(data, Htype)%>%summarise(count=n(), mean=mean(Camt, na.rm=TRUE))

#ANOVA
result=aov(Camt~Htype, data=data)
summary(result)

TukeyHSD(result)

#Homogeneity of variances (equal variances assumption)
plot(result, 1)

#Normality assumption
plot(result,2)

# Kruskal-Wallis rank sum test (used when ANOVA assumptions are not met)
kruskal.test(Htype~Camt, data=data)
