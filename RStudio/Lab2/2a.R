rm(list=ls())

#1
df<-data.frame(Student=c("Harry", "Ron", "Percy", "James", "Luna"),
               Badminton=c(10,9,0,3,8),
               Tennis=c(8,5,9,3,9),
               Athletics=c(5,0,3,9,5),
               Football=c(3,6,8,9,9))
               

#2
df

#3
df$total=rowSums(df[,2:5])

#4
df$Quiz<-c(4,5,6,3,8)
df

#5
df$Student[which.max(df$total)]

#6
d=data.frame(Student="Avg", Badminton=mean(df$Badminton), Tennis=mean(df$Tennis), Athletics=mean(df$Athletics),Football=mean(df$Football), total=mean(df$total), Quiz=mean(df$Quiz))
d
df=rbind(df,d)
df

#7
write.csv(df,"Events.csv",row.names = FALSE)

#8
new_df=read.csv("Events.csv")
new_df

#9
new_df[,3]

#10
new_df[3,4]

#11
new_df[1:2,]

#12
new_df[,c(1,6)]

#13
row.names(new_df)<-new_df$Student

new_df

#14
new_df[which(new_df$Athletics!=0),1]
new_df

#15
new_df$Student[which(new_df$total>new_df$total[6])]
