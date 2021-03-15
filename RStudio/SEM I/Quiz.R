x<-c("a", "b","c")
as.numeric(x)

x<- c(10,NA, 25, NA, 36)
is.na(x)

x<-list(1, "a","5", FALSE)
x[3]
x[[3]]

x<-c(2,3,4)
y<-c(10,20,30)
dim(rbind(x,y))
class(rbind(x,y))
typeof(rbind(x,y))

x <- list(tttxxxttt="hai")
x[["t",exact=FALSE]]

x<-7
class(x)

x<-c("2", 6.5,9L)
class(x)

x<-list(empid=50001, name="Raja" , doj="12-04-2015", dept="production")
x$dept
x["dept"]
x[4]
x[[4]]
x[["dept"]]

x<-matrix(1:10, 2,5)
x[1,3]

