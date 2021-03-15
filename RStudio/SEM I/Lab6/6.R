#1
library(MASS)
library(dplyr)
rm(list=ls())

#2
sum(is.na(survey))

#3
newsurvey=na.omit(survey)

#4
table(newsurvey$Sex)

#5
table(newsurvey$W.Hnd)


#6
freq=table(newsurvey$W.Hnd)
rel=freq/nrow(newsurvey)
round(rel,2)

#7
c=newsurvey[which(newsurvey$W.Hnd=='Left'),]
cbind(table(c$Sex))

#8
c=newsurvey[which(newsurvey$Sex=='Male'& newsurvey$W.Hnd=='Left'),]
d=c[which(c$Smoke=='Never'),]
d
perc=nrow(d)/nrow(c)*100
perc

#9
range(newsurvey$Age)

#10
round(range(newsurvey$Age))
breaks<-round(seq(17,70,by=10))
Age_split<-cut(newsurvey$Age,breaks,right=F)
Age_split_freq<-table(Age_split)
Age_split_freq


#11
df<-cbind(Age_split_freq)
df


#12
which.max(Age_split_freq)


#13
range(newsurvey$Wr.Hnd)
breaks<-round(seq(13.0,23.2,by=1.0))
Wr.Hnd_split<-cut(newsurvey$Wr.Hnd,breaks,right=F)
Wr.Hnd_split_freq<-table(Wr.Hnd_split)
df<-cbind(Wr.Hnd_split_freq)
df

#14
rel=Wr.Hnd_split_freq/nrow(newsurvey)
cbind(round(rel,3))

#15
mean(newsurvey$Age)

#16
sd(newsurvey$Height)
var(newsurvey$Height)

#17
quantile(newsurvey$Wr.Hnd)

#18
cor(newsurvey$Wr.Hnd, newsurvey$Pulse)

#19
newsurvey%>%
  group_by(Exer)%>%
  summarise(mean(Age))

#20
newsurvey%>%
  group_by(NW.Hnd)%>%
  summarise(sd(Height))

#21
summary(newsurvey$Pulse)
