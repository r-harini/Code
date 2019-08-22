u=[1,2,3,4,5]
p=[5,4,3,2,2]
i=0
j=len(p)-1
while(i<len(u) & j>0):
    if (u[i]==p[j]):
        i+=1
        j-=1
    else:
        print("Invalid")
        break
