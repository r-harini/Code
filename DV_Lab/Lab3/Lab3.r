install.packages("corrplot")
library(corrplot)
dataset=quakes
cm=cor(dataset)
corrplot(cm, method="circle")

corrplot(cm, method="pie")

corrplot(cm, method="square")

corrplot(cm, method="number")

corrplot(cm, method="color")

corrplot(cm, method="ellipse")

corrplot(cm, method="shade")

corrplot(cm, type="upper")

corrplot(cm, type="lower")

corrplot.mixed(cm)

corrplot.mixed(cm, lower.col = "black", number.cex = .7)

corrplot.mixed(cm, lower = "ellipse", upper = "circle")

corrplot.mixed(cm, lower = "square", upper = "circle", tl.col = "black")

corrplot(cm, order = "hclust", addrect = 2)

library(ggplot2)
install.packages("ggalt")
library(ggalt)

dataset_select=dataset[dataset$lat<(-20) & dataset$long>180 & dataset$depth>200 & dataset$mag<(4.5) & dataset$stations<20, ]
#ScatterPlot with encircling
ggplot(dataset, aes(x=lat, y=long))+ 
  geom_point(aes(col=depth, size=mag))+geom_smooth(method="loess", se=F)+
  xlim(c(-30, 30))+ 
  ylim(c(100,200))+
  geom_encircle(aes(x=lat, y=long), data=dataset_select, color="red", size=2, expand=0.08)+
  labs(subtitle="Latitude vs Longitude",
       y="Longitude", x="Latitude", title="Scatterplot+ Encircle", caption="Source: Quakes")
  
#Jitter Plot
g=ggplot(dataset, aes(lat, long))
g+geom_point()+geom_smooth(method="lm", se=F)+labs(subtitle = "Latitude vs Longitude", y="Latitude", x="Longitude", title="Jitter Plot", caption="Source:Quakes")
theme_set(theme_bw())
g+geom_jitter(width=.5, size=1)+labs(subtitle = "Quakes: Latitude vs Longitude", y="Longitude", x="Latitude", title="Jittered Points")

#Counts Chart
g+geom_count(col="red", show.legend = F)+labs(subtitle = "Latitude vs Longitude", y="Latitude", x="Longitude", title="Counts Plot")

#Bubble Chart
gg=ggplot(dataset_select, aes(lat, long))+ labs(subtitle="Quakes: Latitude vs Longitude", title="Bubble Plot")
g+geom_jitter(aes(col=depth, size=mag))+geom_smooth(aes(col=depth), method="lm", se=F)
