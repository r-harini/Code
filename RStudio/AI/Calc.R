library(ggplot2)

df=read.csv("ConvNet.csv")
colnames(df)[1]="Sign"
ggplot(df, aes(x=Sign, y=GPU, fill="red"))+geom_bar(stat="identity")+geom_text(aes(label=GPU))+theme_minimal()+ylab("Distance for GPU")+xlab("Traffic Sign")
ggplot(df, aes(x=Sign, y=CPU, fill="red"))+geom_bar(stat="identity")+geom_text(aes(label=CPU))+theme_minimal()+ylab("Distance for CPU")+xlab("Traffic Sign")

d=cbind(df$GPU, df$CPU)

library(reshape2)
df2=melt(df,id.vars='Sign')

ggplot(df2,aes(x=Sign, y=value, fill=variable))+geom_bar(stat="identity", position = "dodge")+geom_text(aes(label=value))+theme_minimal()+ylab("Distance")+xlab("Traffic Sign")

df=read.csv("ML.csv")
colnames(df)[1]="Sign"
ggplot(df, aes(x=Sign, y=GPU, fill="red"))+geom_bar(stat="identity")+geom_text(aes(label=GPU))+theme_minimal()+ylab("Distance for GPU")+xlab("Traffic Sign")
ggplot(df, aes(x=Sign, y=CPU, fill="red"))+geom_bar(stat="identity")+geom_text(aes(label=CPU))+theme_minimal()+ylab("Distance for CPU")+xlab("Traffic Sign")

d=cbind(df$GPU, df$CPU)

library(reshape2)
df2=melt(df,id.vars='Sign')

ggplot(df2,aes(x=Sign, y=value, fill=variable))+geom_bar(stat="identity", position = "dodge")+geom_text(aes(label=value))+theme_minimal()+ylab("Distance")+xlab("Traffic Sign")
