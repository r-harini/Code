target= int(input('Enter target: '))

arr=[]
n=int(input('Enter num of elements: '))

for i in range(n):
    a=int(input('Enter ele: '))
    arr.append(a)

def how(target, arr):
    if target==0:
        return []
    elif target<0:
        return None
    
    for num in arr:
        remainder= target-num
        newarr=how(remainder,arr)
        


