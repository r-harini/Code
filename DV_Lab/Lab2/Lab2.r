hsb2=read.table("/home/bigdata/Desktop/18BCE1010/Lab2/hsb2.csv", header=T, sep=",")
attach(hsb2)
library(lattice)
hsb2$prog.f=factor(hsb2$prog, labels=c("low", "middle", "high"))
histogram(~write|prog.f, hsb2)

hsb2$female.f=factor(hsb2$female, labels=c("low", "high"))
histogram(~write|female.f, hsb2)

reg=lm(read~math, hsb2)
par(mfrow=c(1:2))
plot(reg, which=1:2)

densityplot(~socst|prog.f, hsb2)