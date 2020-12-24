m=int(input('Enter m: '))
n=int(input('Enter n: '))


def grid(m,n,d):
    if m==0 or n==0:
        d[m][n]=0
        return 0
    elif m==1 and n==1: 
        d[m][n]=1
        return 1
    elif d[m][n]>-1:
        return d[m][n]
    else:
        d[m][n]=grid(m-1,n,d)+ grid(m,n-1,d)
        return d[m][n]


d=[[-1 for i in range(n+1)] for j in range(m+1)]

print(grid(m,n,d))
    