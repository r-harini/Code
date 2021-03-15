rm(list=ls())

library(tidyr)
library(dplyr)

cust=read.csv("telecom.csv")
class(cust)
str(cust)

cust$MonthlyCharges
is.na(cust$MonthlyCharges)

cust%>%
  filter(Churn=="yes")%>%
  select(customerID,TotalCharges)

cust%>%
  distinct(MonthlyCharges)

df%>%
  group_by(Sex)%>%
  summarise(mean(Pulse))


