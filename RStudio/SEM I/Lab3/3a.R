rm(list=ls())

#1
library(MASS)
library(dplyr)

newsurvey=na.omit(survey)

#2
filter(newsurvey, Sex=="Male", W.Hnd=="Left")

#3
filter(newsurvey, Sex=="Female", Clap=="Right")

#4
filter(newsurvey, Exer=="None")

#5
dplyr::select(newsurvey,Sex, Age, W.Hnd)

#6
newsurvey%>%
  filter(W.Hnd=="Left", Sex=="Female")%>%
  dplyr::select(Age, Pulse, Wr.Hnd)
  
#7
arrange(newsurvey, desc(Height))%>%filter(Sex=="Male", W.Hnd=="Left")

#8
mutate(newsurvey, Diff=Wr.Hnd-NW.Hnd)%>%
  dplyr::select(Sex,Wr.Hnd, NW.Hnd, Diff)

#9
newsurvey%>%
  filter(W.Hnd=="Left")%>%
  group_by(Sex)%>%
  summarise(mean(Wr.Hnd))


#10
newsurvey%>%
  filter(Sex=="Male")%>%
  group_by(W.Hnd)%>%
  summarise(max(Pulse))


B=rep(c("X","Y"), each=3)
B
