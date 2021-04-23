#https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
a=list(map(int,input().split()))
#By comparing in pairs we can solve it 
n=len(a)
i=0
j=0
while i<n:
    if a[i]<0:
        a[i],a[j]=a[j],a[i]
        j=j+1
    i=i+1
print(a)