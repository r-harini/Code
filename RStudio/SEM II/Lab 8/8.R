rm(list=ls())
setwd("C:/Code/RStudio/SEM II/Lab 8")

data <- read.csv("iris.csv",row.names=1)

#as it is distance based metric, we scale to obtain better accuracy.
df <- scale(data) 

#computing dis-similarity matrix
dissim <- dist(df, method = 'euclidean')

hierClust <- hclust(dissim, method = 'complete')
plot(hierClust)
cluster <- cutree(hierClust, k = 3)

#minimize inter-cluster distance and maximize intra-cluster distance

library(clValid)

#higher the dunn index, more compact(better) the clusters are
dunn(dissim, cluster)
 
# plot(hclust_avg)
rect.hclust(hierClust, k = 3, border = 2:4)
abline(h = 3, col = 'red')

Kmax <- 10
D <- rep(0,Kmax)
for (i in 2:Kmax){
  cluster<- cutree(hierClust, k=i)
  D[i] <- dunn(dissim, cluster)
}
plot(2:Kmax,D[2:Kmax],type="b",pch=19)

# Best value of k is the one with the ighest Dunn index