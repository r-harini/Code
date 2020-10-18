rm(list=ls())

library(MASS)
library(dplyr)

df=na.omit(survey)

#1
c=df%>%
  group_by(Sex)%>%
  tally()
c=pull(c,n)
c=table(df$Sex)
c
barplot(c, main="Male and Female participants", ylab = "frequency", col=c("blue", "red"), names.arg = levels(df$Sex))

#2
c=df%>%
  group_by(W.Hnd)%>%
  tally()
c=pull(c)
c=table(df$W.Hnd)
barplot(c, main="Left Handers and Right Handers", ylab="count", col=c("yellow", "green"), names.arg=levels(df$W.Hnd))

#3
c=df%>%
  filter(W.Hnd=="Left")%>%
  group_by(Sex)%>%
  tally()
c=pull(c)
barplot(c,main="Female left handers and Male Left Handers", ylab="count", col=c("blue", "yellow"), names.arg=levels(df$Sex))

#4
c=df%>%
  filter(Sex=="Male" & W.Hnd=="Left")%>%
  group_by(Smoke)%>%
  tally()
c=pull(c,n)
pie(c, levels(df$Smoke), main="Smoking Habits of Male Left Handers")

#5
hist(df$Age, main="Age Distribution", xlab="Age range", ylab="Frequency", col="light blue")

#6
plot(df$Age, df$Wr.Hnd)

#7
boxplot(df$Pulse, main="Pulse Rate", ylab="Pulse values", xlab="Pulse")
summary(df$Pulse)

