n=int(input("Enter n: "))

def fib(n, memo):
    if n in memo.keys():
        return memo[n]
    elif n<=2: 
        return 1
    else:
        memo[n]=fib(n-1, memo)+ fib(n-2,memo)
        return memo[n]
def opt(n):
    if n<=2:
        return 1
    i=2
    a,b=1,1
    while i<n:
        a,b=b,a+b
        i+=1
    return b
memo={}
print(fib(n,memo))
print(opt(n))