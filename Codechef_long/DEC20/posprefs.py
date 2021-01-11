import math
for _ in range (int(input())):
    #n=int(input())
    n,k=list(map (int,input ().split()))
    #a=list(map (int,input ().split()))
    #b=list(map (int,input ().split()))
    s=0
    print(1,end=" ")
    for i in range (2,n+1):
        if (i-1)%2==0:
            print(i,end=" ")
        else:
            print(-i,end=" ")
        
    print()