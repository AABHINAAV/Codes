for _ in range (int(input())):
    #n=int(input())
    a,b=list(map (int,input ().split()))
    #a=list(map (int,input ().split()))
    #b=list(map (int,input ().split()))
    c=0
    '''for i in range (1,a+1):
        for j in range (1,b+1):
            if (i+j)%2==0:
                c=c+1
    print(c)'''
    if a%2!=0 and b%2!=0:
        print(a*b//2 +1)
    else:
        
        print(a*b//2)