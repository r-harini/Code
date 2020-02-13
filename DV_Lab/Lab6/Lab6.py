# -*- coding: utf-8 -*-
"""
Created on Tue Feb  4 16:19:46 2020

@author: rhari
"""

import pandas as pd
from ggplot import *
g1=ggplot(aes(x='carat', y='price'), data=diamonds) +geom_area()+ggtitle("Carat vs Price")
g1.show()

g2=ggplot(aes(x='carat', y='price'), data=diamonds)+ geom_jitter()+ggtitle("Carat vs Price")
g2.show()

g3=ggplot(aes(x='carat', color='cut'), data=diamonds)+ geom_point()+ggtitle("Carat vs Price")
g3.show()

g4=g2+theme_bw()
g4.show()

g5=ggplot(aes(x='carat', y='price', size='cut'), data=diamonds)+geom_point()
g5.show()

g6=ggplot(aes(x='carat', y='price'), data=diamonds)+ geom_jitter(alpha=0.6)+ggtitle("Carat vs Price")
g6.show()

g7=ggplot(aes(x='carat', y='price', color='clarity'), data=diamonds)+geom_point(alpha=.4)
g7.show()

g8=ggplot(aes(x='carat', y='price', color='clarity'), data=diamonds)+geom_jitter()+facet_grid('cut')
g8.show()

g9=ggplot(aes(x='carat', y='price'), data=diamonds)+geom_bar()
g9.show()

g10=ggplot(aes(x='carat', y='price'), data=diamonds)+geom_bar(fill='red', colour='white')
g10.show()

g11=ggplot(aes(x='carat', y='price'), data=diamonds)+geom_boxplot()
g11.show()

g12=ggplot(aes(x='carat', y='price'), data=diamonds) +geom_area(alpha=0.5)+ggtitle("Carat vs Price")
g12.show()

g13=ggplot(aes(x='carat', y='price'), data=diamonds) +geom_area(fill='red')+ggtitle("Carat vs Price")
g13.show()

g15=ggplot(aes(x='carat', y='price'), data=diamonds)+ geom_density()
g15.show()

g16=ggplot(aes(x='carat', y='price'), data=diamonds)+geom_histogram()
g16.show()

g17=ggplot(aes(x='carat', y='price'), data=diamonds)+ geom_histogram(bins=200)
g17.show()

g18=ggplot(aes(x='carat', y='price'), data=diamonds)