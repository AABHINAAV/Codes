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
def func2(h,x,y,st,e):
    if(e<st):
        return 0
    if(y<0):
        return 0
    for i in range (st,e):
        if h[i]>=x and h[i]<=y:
            return 1
    return 0
def func1(s,h,index,n,x,y):
    if (s[index]<=y):
        print(0)
        return
    ans=0
    for i in range (n):
        for j in range (i+1):
            ans=ans+func2(h,x-s[i]+h[j],y-s[i]+h[j],i+1,n)
            if ans>=1:
                print(1)
                return
    #        
    print(2)
    return
def solve():
    #n=int(input())
    n,x,y=list(map (int,input ().split()))
    h=list(map (int,input ().split()))
    #b=list(map (int,input ().split()))
    su=0
    index=-1
    s=[]
    for i in range(n):
        su=su+h[i]
        s.append(su)
        if (su>=x and index==-1):
            index=i
    func1(s,h,index,n,x,y)
for _ in range (int(input())):
    solve()
        