rm(list=ls())
mydat <- PlantGrowth
str(mydat)
unique(mydat$group)
#sample data
library(dplyr)
set.seed(123)
sample_n(mydat,10)

#check the levels of factored variable
levels(mydat$group)

#if not ordered, it can be reordered as follows
mydat$group <- ordered(mydat$group,levels=c("ctrl","trt1","trt2"))

#compute summary statistics by group -count, mean and std.dev
mydat %>%
  group_by(group) %>%
  summarise(count=n(),mn=mean(weight,na.rm = TRUE),stddev=sd(weight,na.rm = TRUE))

#visualize the data
library(ggplot2)
ggplot(mydat,aes(x=group,y=weight))+geom_boxplot()

library(ggpubr)                                             
ggboxplot(mydat,x="group",y="weight",color="group",palette = c("red","green","blue"))

#mean plots
#plot weight by group
#add error bars: mean_se
ggline(mydat,x="group",y="weight")
ggline(mydat,x="group",y="weight",add = c("mean_se","jitter"))

#compute analysis of variance
res <- aov(weight~group,data=mydat)

#summary of analysis
summary.aov(res)

#Tukey HSD -multiple pairwise comparison
TukeyHSD(res)

#checking homogeneity of variance
plot(res,1)
par(mar=c(2,2,2,2))
#Levene's Test
library(car)
leveneTest(weight~group,mydat)

#relaxing the homogeneity 
oneway.test(weight~group,mydat)

#checking normality
plot(res,2)

#shapiro_wilk test on ANOVA residuals
#Extract the residuals
res_resi <- residuals(res)
shapiro.test(res_resi)

#Non-parametric alternative to one-way ANOVA test
kruskal.test(weight~group,mydat)


#####Two way ANOVA #######
#Two-way ANOVA test is used to evaluate simultaneously 
#the effect of two grouping variables (A and B) on a response variable.
mydat2 <- ToothGrowth
str(mydat2)

#random sample
set.seed(1)
sample_n(mydat2,10)


#convert dose type as factor
unique(mydat2$dose)
mydat2$dose <- factor(mydat2$dose,levels = c("0.5","1","2"),labels = c('D0.5','D1','D2'))
head(mydat2)

#summary statistics
mydat2%>%
  group_by(dose,supp)%>%
  summarise(count=n(),mn=mean(len,na.rm = TRUE),std=sd(len,na.rm = TRUE))


#visualize the data
ggboxplot(mydat2,x="dose",y="len",color="supp",palette = c("red","blue"))


## Line plots with multiple groups
# Plot tooth length ("len") by groups ("dose")
# Color box plot by a second group: "supp"
# Add error bars: mean_se
ggline(mydat2,x="dose",y="len",color="supp",add = c("mean_se","dotplot"),palette = c("red","green"))

#Question of interest -  We want to know if tooth length depends on supp and dose.

#frequency table - check balanced design
table(mydat2$supp,mydat2$dose)


#compute two-way anova test (additive model- two factors are independent)
res2 <- aov(len~supp+dose,mydat2)
summary(res2)

# compute two-way anova with interaction
res3 <- aov(len~supp*dose,mydat2)
summary(res3)



#Tukey multiple pairwise comparisons
TukeyHSD(res2,which = "dose")

#testing homogeneity
plot(res2,1)

leveneTest(len~supp*dose,mydat2)

#testing normality
plot(res2,2)

res2_resi <- residuals(res2)
shapiro.test(res2_resi)

#when the design is unbalanced
my_anova <- aov(len~supp*dose,mydat2)
Anova(my_anova,type='III')


#MANOVA
mydat3 <- iris

#sampling
set.seed(2)
sample_n(mydat3,10)

#Question: We want to know if there is 
#any significant difference, in sepal and petal length, 
#between the different species.
#MANOVA test
res4 <- manova(cbind(iris$Sepal.Length,iris$Petal.Length)~iris$Species,mydat3)
summary(res4)

#to know the significance on one or both variables
summary.aov(res4)
