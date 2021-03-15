rm(list=ls())
a <- read.csv("weatherHistory.csv") 

# Multiple linear regression
mlr= lm(Temperature..C.~Apparent.Temperature..C.+Humidity+Wind.Speed..km.h., a) 
summary(mlr)
qqnorm(mlr$resid)   #Q-Q Plot

# Time-series analysis
data <- ts(a$Temperature..C., start=as.Date("2014-01-01"), end=as.Date("2014-12-31"), frequency=24)
frequency(data)
summary(data)

# plotting the series
plot(data)

# day-wise mean plot
plot(aggregate(data,FUN=mean))

# hour-wise box plot
boxplot(data~cycle(data))

# install.packages("forecast")
library(forecast)

# Autocorrelation and Partial Autocorrelation plots
acf(data)

# Time-series forecasting (Auto ARIMA) 
fit <- auto.arima(data)
accuracy(fit)
# for 10 days so 24*10=240
newdata <- forecast(fit, 240)
plot(newdata)
