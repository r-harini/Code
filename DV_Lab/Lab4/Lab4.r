install.packages("corrplot")
library(corrplot)
dataset=quakes

#Marginal Histogram/Boxplot
library(ggplot2)
install.packages("ggExtra")
library(ggExtra)
theme_set(theme_bw())
dataset_select=dataset[dataset$lat<(-20) & dataset$long>180,]
g=ggplot(dataset, aes(lat, long))+geom_count()+geom_smooth(method="lm", se=F)
ggMarginal(g, type="histogram", fill="transparent")
ggMarginal(g, type="boxplot", fill="transparent")

#Correlogram
install.packages("ggcorrplot")
library(ggcorrplot)
corr=round(cor(dataset),1)
ggcorrplot(corr, hc.order = TRUE, type="lower",
           lab=TRUE, lab_size=3,
           method="circle",
           colors=c("red", "white", "green"),
           title="Correlogram of quakes",
           ggtheme=theme_bw())

#Diverging bars
dataset$'name'=rownames(dataset)
dataset$lat_z=round((dataset$lat-mean(dataset$lat))/sd(dataset$lat),2)
dataset$lat_type=ifelse(dataset$lat<(-20), "below", "above")
dataset=dataset[order(dataset$lat_z),]
dataset$name=factor(dataset$name, levels = dataset$name)
ggplot(dataset, aes(x=name, y=lat_z, label=lat_z))+
  geom_bar(stat="identity", aes(fill=lat_type), width=.5)+
  scale_fill_manual(name="Quakes", labels=c("Above Average", "Below Average"),
                    values=c("above"="#00ba38", "below"="#f8766d"))+
  labs(subtitle="Normalised Latitude from 'quakes'", title="Diverging Bars")+coord_flip()

#Diverging lollipop
ggplot(dataset, aes(x=name, y=lat_z, label=lat_z))+
  geom_point(stat="identity", fill="black", size=6)+
  geom_segment(aes(y=0, x=name, yend=lat_z, xend=name), color="black")+
  geom_text(color="white", size=2)+
  labs(title="Diverging Lollipop Chart", subtitle="Normalised Latitudes from Quakes: Lollipop")+
  ylim(-2.5,2.5)+coord_flip()

#Diverging Dot plot
ggplot(dataset, aes(x=name, y=lat_z, label=lat_z)) +
  geom_point(stat='identity', aes(col=lat_type), size=6)  +
  scale_color_manual(name="Latitude",
                     labels = c("Above Average", "Below Average"),
                     values = c("above"="#00ba38", "below"="#f8766d")) +
  geom_text(color="white", size=2) +
  labs(title="Diverging Dot Plot",
       subtitle="Normalized Latitude from 'quakes': Dotplot") +
  ylim(-2.5, 2.5) +
  coord_flip()

#Area Chart
install.packages("quantmod")
library(quantmod)
economics$returns_perc <- c(0, diff(economics$psavert)/economics$psavert[-length(economics$psavert)])
brks <- economics$date[seq(1, length(economics$date), 12)]
lbls <- lubridate::year(economics$date[seq(1, length(economics$date), 12)])
ggplot(economics[1:100, ], aes(date, returns_perc)) + 
  geom_area() + 
  scale_x_date(breaks=brks, labels=lbls) + 
  theme(axis.text.x = element_text(angle=90)) + 
  labs(title="Area Chart", 
       subtitle = "Perc Returns for Personal Savings", 
       y="% Returns for Personal savings", 
       caption="Source: economics")