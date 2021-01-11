from collections import defaultdict
from collections import deque

class Node():
    def __init__(self,index=None,weight=None,parent=None):
        self.index=index
        self.weight=weight
        self.child=[]
        self.parent=parent
        self.f=[]
n,q=map(int,input().split())
w=list(map(int,input().split()))
dic={}
dp={}
for i in range(1,n+1):
    dic[i]=Node(index=i,weight=w[i-1])
dic2=defaultdict(list)
for i in range(n-1):
    u,v=map(int,input().split())
    dic2[u].append(v)
    dic2[v].append(u)
que=deque([1])
done=set([1])
dic[1].f=[dic[1].weight]
while que:
    parent=que.popleft()
    for child in dic2[parent]:
        if child in done:
            None
        else:
            dic[parent].child.append(dic[child])
            dic[child].parent=dic[parent]
            dic[child].f=dic[parent].f+[dic[child].weight]
            que.append(child)
            done.add(child)
for i in range(q):
    u,v=map(int,input().split())
    if (u,v) in dp:
        print(dp[(u,v)])
    else:
        x=len(dic[u].f)
        uval=dic[u].f
        vval=dic[v].f
        ans=0
        for i in range(len(uval)):
            ans+=uval[i]*vval[i]
        ans=ans%(2**32)
        dp[(u,v)]=ans
        print(ans)
