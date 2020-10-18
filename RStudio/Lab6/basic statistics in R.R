library(MASS)   #MASS - Modern Applied Statistics with S
str(painters)
#Qualitative data
#compute the frequency distribution of school variable
sch_freq <- table(painters$School)
cbind(sch_freq)

#which school has got the most painters
max(sch_freq)
which.max(sch_freq)


#compute the relative frequency of school variable
rel_sch_frequ <- sch_freq/nrow(painters)
cbind(rel_sch_frequ)


old <- options(digits = 1)
rel_sch_frequ
cbind(rel_sch_frequ)
options(old)

#bar graph
par("mar")
par(mar=c(1,1,1,1))
barplot(sch_freq)
pie(sch_freq)

#find the mean composition of painters in school 'C'
c_p <- painters[painters$School=='C',]
mean(c_p$Composition)

options(digits=2)
#find the mean composition of painters in all schools
tapply(painters$Composition, painters$School, mean)


#Quantitative data
head(faithful)   #data of Old faithful geyser in USA Yellowstone National Park
str(faithful)


#frequency distribution of eruption duration
erup_dur <- faithful$eruptions
range(erup_dur)    #find the range of duration

breaks <- seq(1.5,5.5,by=0.5)  #obtain equal distance non-overlapping sub-intervals
breaks

erup_dur_split <- cut(erup_dur,breaks,right=FALSE)
erup_dur_split_freq <-table(erup_dur_split)
erup_dur_split_freq
cbind(erup_dur_split_freq)

#which range has the maximum frequency
which.max(erup_dur_split_freq)

#histogram
hist(erup_dur,right=FALSE)

#compute relative frequency
erup_dur_relfreq <- erup_dur_split_freq/nrow(faithful)
cbind(erup_dur_relfreq)


#cumulative frequency distribution
erup_dur_cumfreq <- cumsum(erup_dur_split_freq)
erup_dur_cumfreq

#cumulative relative frequency distribution
erup_dur_cumfreq/nrow(faithful)


##Numerical measures
#mean
erup_dur
mean(erup_dur)

#mdeian
median(erup_dur)

#quartile
quantile(erup_dur)

#percentile
quantile(erup_dur,c(.35,.45,.72))

#range
range(erup_dur)
max(erup_dur)-min(erup_dur)

#Interquartile range
IQR(erup_dur)

#boxplot
boxplot(erup_dur)

options(digits = 5)
#variance
var(erup_dur)

#standard deviation
sd(erup_dur)

#covariance
wait_len <- faithful$waiting
cov(erup_dur,wait_len)

#correlation
cor(erup_dur,wait_len)


#central moment
library(e1071)
moment(erup_dur,order=3,center = TRUE)


#skewness
skewness(erup_dur)
#mean(erup_dur)
#median(erup_dur)

#kurtosis
kurtosis(erup_dur)
hist(erup_dur)
