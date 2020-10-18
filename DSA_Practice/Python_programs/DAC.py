def getmax(a, ind):
    if (ind>=len(a)-2):
        if (a[ind]>a[ind+1]):
            return a[ind]
        else:
            return a[ind+1]
    else:
        max=getmax(a, ind+1)

        if (a[ind]>max):
            return a[ind]
        else:
            return max

def merge(a,l,m,r):
    l=[]
    r=[]
    n1
    for i in range(l,m):


def mergesort(a,l,r):
    if (l<r):
        m=(l+r)/2
        x=mergesort(a,l,m)
        y=mergesort(a,m+1,r)
        merge(a,l,m,r)


a=[4,7,3,9,10,5,8]
print(getmax(a,0))
