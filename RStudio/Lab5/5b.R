rm(list=ls())

library(MASS)
library(dplyr)
df=na.omit(survey)

#1
#install.packages("ggplot2")
library(ggplot2)

#2
ggplot(df, aes(x=Sex))+geom_bar(fill=c("red", "blue"))+ggtitle("Male and Female Participants")

#3
ggplot(df, aes(x=W.Hnd))+geom_bar(fill=c("yellow", "green"))+ggtitle("Left and Right Handers")

#4
c=df%>%
  filter(W.Hnd=="Left")
ggplot(c, aes(x=Sex))+geom_bar(fill=c("blue", "yellow"))+ggtitle("Female and Male Left Handers")

#5
c=df%>%
  filter(Sex=="Male" & W.Hnd=="Left")
ggplot(c, aes(x=Age,y=Smoke, fill=Smoke))+geom_bar(stat="identity", width=1)+coord_polar("y", start=0)

#6
ggplot(df, aes(x=Age))+geom_histogram(fill="light blue")+ggtitle("Age Distribution")+ylab("Frequency")+xlab("Age Range")

#7
ggplot(df, aes(x=Age, y=Wr.Hnd))+geom_point()

#8
c=df%>%
  filter(W.Hnd=="Left")
ggplot(c, aes(x=Wr.Hnd, y=Pulse,color=Sex, size=Height))+geom_point()

#9
ggplot(df , aes(x=Sex, y= Height,color=Sex)) +geom_point()+facet_wrap(~W.Hnd)

#10
ggplot(df,aes(x=Wr.Hnd,y=NW.Hnd,color=W.Hnd))+geom_point()+facet_wrap(~Clap)+labs(title = "claps")

#11
ggplot(df,aes(x=Exer,y=Age))+geom_point()+facet_wrap(~Sex)

#12
ggplot(df,aes(x=Smoke,y=Wr.Hnd))+geom_boxplot()

