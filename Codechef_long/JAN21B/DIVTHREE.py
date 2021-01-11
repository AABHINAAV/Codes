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
for _ in range (int(input())):
    #n=int(input())
    n,k,d=list(map (int,input ().split()))
    a=list(map (int,input ().split()))
    #b=list(map (int,input ().split()))
    m=sum(a)//k
    if m>d:
        print(d)
    else:
        print(m)