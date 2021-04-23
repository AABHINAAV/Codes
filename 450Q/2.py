#https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
a=list(map(str,input().split()))
#By comparing in pairs we can solve it 
n=len(a)
i=1
mi=mx=a[0]
while i<n:
    mi=min(mi,a[i])
    mx=max(mx,a[i])
    i+=1
print(mi,mx)
