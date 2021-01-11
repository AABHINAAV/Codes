# def SieveOfEratosthenes(n): 
# 	prime = [True for i in range(n+1)] 
# 	p = 2
# 	while (p * p <= n): 

# 		if (prime[p] == True): 

# 			for i in range(p * p, n+1, p): 
# 				prime[i] = False
# 		p += 1
     
# 	for p in range(2, n+1): 
# 		if prime[p]: 
# 			l.append(p)
# l=[]
# SieveOfEratosthenes(2*19999909)
def solve():
    #n=int(input())
    n,k,x,y=list(map (int,input ().split()))
    #a=list(map (int,input ().split()))
    #b=list(map (int,input ().split()))
    if x==y:
        print(n,n)
        return
    a=[[0,0],[0,0],[0,0],[0,0]]
    if x>y:
        y=n+y-x
        x=n
        a[1][0]=x
        a[1][1]=y
        x=y+x-n
        y=n
        a[2][0]=x
        a[2][1]=y
        y=y-x
        x=0
        a[3][0]=x
        a[3][1]=y
        x=y+x
        y=0
        a[0][0]=x
        a[0][1]=y
    else:
        x=n-y+x
        y=n
        a[1][0]=x
        a[1][1]=y
        y=y+x-n
        x=n
        a[2][0]=x
        a[2][1]=y
        x=x-y
        y=0
        a[3][0]=x
        a[3][1]=y
        y=y+x
        x=0
        a[0][0]=x
        a[0][1]=y
    k=k%4
    print(a[k][0],a[k][1])
    return
for _ in range (int(input())):
    solve()
        