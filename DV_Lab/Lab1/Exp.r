Data=read.csv("C:/Code/DV_Lab/Lab1/Dataset.csv", fileEncoding="UTF-8-BOM")
xi=Data$Age.Group
yi=Data$Number.of.Loans
plot(xi,yi,type='h',color='purple')
zi=Data$Bad.Rate
df=data.frame(xi,yi,zi)
ggplot(data=df, aes(x=xi, y=yi)) + geom_bar(stat="identity", fill="black")+xlab("Age Groups")+ylab("Number Of Loans")
ggplot(data=df) + geom_bar(aes(x=xi, y=yi),stat="identity", fill="black")+geom_line(aes(x=xi, y=zi),stat="identity",group=1)+
  scale_y_continuous(sec.axis = sec_axis(~./max(df$yi)))

ggplot(df) +
  geom_col(aes(x = xi, y = yi)) +
  geom_line(aes(x = xi, y = zi/0.0005,colour = "Bad.Rate", group = 1),
             size = 1) +
  scale_y_continuous(sec.axis = sec_axis(~.*0.0005, name = "BadRate")) +
  labs(y = "No. 0f Loans", x = "Age")+
  scale_colour_manual("", breaks=c("Bad.Rate"),values=c("red"))+
  theme(legend.position = c(0.9, 0.95))
