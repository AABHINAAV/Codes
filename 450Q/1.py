#https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
a=list(map(str,input().split()))

##1

# x=0
# c=len(a)-1
# while x<c:
#     a[x],a[c]=a[c],a[x]
#     c=c-1
#     x=x+1
# print(*a)

##2

#print(a[::-1])

##3

for i in range (len(a)-1,-1,-1):
    print(a[i])    
