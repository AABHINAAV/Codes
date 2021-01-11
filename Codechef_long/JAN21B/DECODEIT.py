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
l=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p']
def solve():
    n=int(input())
    #a,b=list(map (int,input ().split()))
    #a=list(map (int,input ().split()))
    #b=list(map (int,input ().split()))
    s=input()
    g=4
    y=""
    i=0
    while g<=n:
        x=int(s[i:g],2)
        #print(x)
        y=y+l[x]
        g=g+4
        i=i+4
    print(y)
for _ in range (int(input())):
    solve()
        