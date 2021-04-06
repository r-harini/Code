setwd("C:/Code/RStudio/SEM II/Lab 7")
rm(list=ls())

data<- read.csv("USArrests.csv",row.names=1)

library(dplyr)
data1<- sample_n(data,30)
df<- scale(data1)
set.seed(112)

fit<- kmeans(df,3)

fit$size
fit$withinss
fit$tot.withinss  # Within Cluster Sum of Squares (WCSS)

Kmax<- 15
WCSS <- rep(NA,Kmax)
nClust<- list()
for (i in 1:Kmax){
  fit<- kmeans(df,i)
  WCSS[i] <- fit$tot.withinss
  nClust[[i]] <- fit$size
}
plot(1:Kmax,WCSS,type="b",pch=19)


# install.packages("factoextra")
library(factoextra)
fviz_nbclust(df, kmeans, method = "wss",k.max = 15)

# install.packages("cluster")
library(cluster)

Kmax<- 15
sil <- rep(0,Kmax)

for (i in 2:Kmax){
  fit<- pam(df, i, metric = "manhattan")
  print(fit$silinfo$avg.width)
  sil[i] <- fit$silinfo$avg.width
}

plot(1:Kmax,sil,type="b",pch=19)

fit<- pam(df, 3, metric = "manhattan") # K-Medoids
print(fit)

fviz_nbclust(df, pam, method = "silhouette")
