#1
c=TRUE
c
as.integer(c)

#2
string='"Do you think this is a game?", he said. "No, I think Jengas a game". Archer responded.'
string

#3
p=4L
q=8L
class(p)
class(q)

#4
tot=p+q
tot
diff=q-p
diff
prod=p*q
prod
quot=q/p
quot

#5
root=sqrt(p)
root
log2(root)

#6
log=log10(100)
cos(pi)*log

#7
x=-2:2
x

#8
y=c(1:10)
y
dim(y)
length(y)

#9
small=c("a", "b", "c", "d", "e")
caps=c("Z", "Y","X","W","V")
rbind(small,caps)
cbind(small,caps)

#10
M=c(1,-2,5,4,8,-1,3,6,7)
dim(M)<-c(3,3)
M
mul=M%*%M%*%M
mul

#11
elementwise=M*M
elementwise

#12
transpose=t(M)
transpose
inverse=solve(M)
inverse
determinant=det(M)
determinant
