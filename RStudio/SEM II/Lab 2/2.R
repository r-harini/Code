rm(list=ls())
data=AirPassengers

start(data)
end(data)
frequency(data) 
cycle(data) 
summary(data) 

# plotting the series 
plot(data) 

#regression 
abline(reg=lm(data~time(data)), col="red") 

#month-wise (range and mean) plot  
monthplot(data) 

# year-wise mean plot 
plot(aggregate(data,FUN=mean)) 

# month-wise box plot 
boxplot(data~cycle(data)) 

#install.packages("forecast") 
library(forecast) 
seasonplot(data) 

# Autocorrelation and Partial Autocorrelation plots 
acf(data) 
pacf(data, lag=length(data),pl=TRUE) 

# ARIMA 
fit <- arima(data, order=c(3, 2, 2))  #order=c(p,d,q)
accuracy(fit)         
newdata <- forecast(fit, 2) 
plot(newdata) 

# Auto ARIMA  
fit <- auto.arima(data) 
newdata <- forecast(fit, 2) 
plot(newdata) 




