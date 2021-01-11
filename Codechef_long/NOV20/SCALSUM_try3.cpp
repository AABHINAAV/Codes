#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
// Declare a multimap 
multimap<int, string> MM; 
# define M_PI  3.14159265358979323846
#define int long long
const int N=3*1e5;
int MOD=(1ll<<32);
vector<int> tree[N], levels[N];

int V[N], P[N], product[N], l_n[N], H[N], occurence[N];

bool looked[N];

vector<int> E, st;
int m, l=0, n, q, sq=50;

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>q;
  int i;
  unordered_map<int, unordered_map<int, int>> mapy;
  for(i=1;i<=n;i++)
    cin>>V[i];
  
  int u, v;
  for(i=0;i<n-1;i++)
  {
    cin>>u>>v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  
  function<void(int, int)> dfs=[&](int node, int h) 
  {
    product[node]=(product[P[node]]+V[node]*V[node])%MOD;
    levels[h].push_back(node);
    if(h>l)
    {
      l=h;
    }
    
    looked[node] = 1;
    E.push_back(node);
    occurence[node]=E.size()-1;
    H[node] = h;
    l_n[node]=h/sq;
    for (auto to : tree[node]) 
    {
      if(looked[to])
        continue;
      P[to]=node;
      dfs(to, h + 1);
      E.push_back(node);
    }
  };
  
  dfs(1, 0);
  m=E.size();
  st.resize(4*m);
  
  function<void(int, int, int)> construct=[&](int node, int b, int e) 
  {
    if(b==e) 
    {
    st[node]=E[b];
    return;
    } 
    
    int mid=(b+e)/2;
    construct(2*node, b, mid);
    construct(2*node+1, mid + 1, e);
    if(H[st[2*node]]<H[st[2*node+1]])
      st[node]=st[2*node];
    else
      st[node]=st[2*node+1];
  };
  construct(1, 0, m - 1);
  function<int(int, int, int, int, int)> query_lca=[&](int node, int b, int e, int L, int R) 
  {
    if (b >= L && e <= R)
      return st[node];
    if (b > R || e < L)
      return -1ll;
    
    int mid = (b + e)/2;  
    int left = query_lca(2*node, b, mid, L, R);
    int right = query_lca(2*node+1, mid + 1, e, L, R);
    if (left == -1) return right;
    if (right == -1) return left;
    if(H[left]<H[right])
      return left;
    else
      return right;
  };
  function<int(int, int)> find_lca=[&](int u, int v)
  {
  
  if(occurence[u]<occurence[v])
    return query_lca(1, 0, E.size() - 1, occurence[u], occurence[v]);
  else
    return query_lca(1, 0, E.size() - 1, occurence[v], occurence[u]);
  };
  for(i=1;i<=n;i++)
    mapy[i];
  i=0;
  while(i<=l)
  {
  
  if(levels[i+1].size()>0 and l_n[levels[i+1][0]]!=l_n[levels[i][0]])
  {
    int j=0;
    int u, v, ans;
    while(j<levels[i].size())
    {
      int k=j+1;
      
      while(k<levels[i].size())
      {
        u=levels[i][j];
        v=levels[i][k];
        ans=0;
        while(u!=v and l_n[P[u]]==l_n[u])
        {
          ans=(ans+V[u]*V[v])%MOD;
          v=P[v];
          u=P[u];
        }
      
        if(u==v)
        {
          mapy[levels[i][j]][levels[i][k]]=(ans+product[u])%MOD;
          mapy[levels[i][k]][levels[i][j]]=(ans+product[u])%MOD;
        }
        else
        {
          ans=(ans+V[u]*V[v])%MOD;
          u=P[u];
          v=P[v];
          
          if(v==u)
          {
            ans=(ans+product[v])%MOD;
            mapy[levels[i][j]][levels[i][k]]=ans;
            mapy[levels[i][k]][levels[i][j]]=ans;
          }
          else
          {
            mapy[levels[i][j]][levels[i][k]]=(ans+mapy[u][v])%MOD;
            mapy[levels[i][k]][levels[i][j]]=(ans+mapy[u][v])%MOD;
          }
        }
          k++;
      }
      j++;
      }
    }
    i++;
  }
  
  while(q--)
  {
  cin>>u>>v;
  int x=u, y=v;
  
  if(mapy[u].find(v)!=mapy[u].end())
    printf("%lld\n", mapy[u][v]);
  else
  {
    int ll=find_lca(u, v);
    if(l_n[ll]==l_n[u])
    {
      int ans=0;
      
      while(u!=v)
      {

ans+=(V[u]*V[v])%MOD

;
        ans%=MOD;
        u=P[u];
        v=P[v];
      }
      ans+=(product[u]);
      ans%=MOD;
      printf("%lld\n", ans);
    }
    else
    {
      int ans=0;
      bool found=false;
      while(l_n[u]==l_n[P[u]])
      {
        if(mapy[u].find(v)!=mapy[u].end())
        {
        found=true;
        ans+=mapy[u][v];
        ans%=MOD;
        break;
        }
        ans+=(V[u]*V[v])%MOD;
        ans%=MOD;
        u=P[u];
        v=P[v];
      }
      
      if(found){
      mapy[x][y]=ans;
      mapy[y][x]=ans;
      printf("%lld\n", ans);
      continue;
    }
    ans+=(V[u]*V[v])%MOD;
    ans%=MOD;
    
    u=P[u];
    v=P[v];
    if(u==v){
    ans+=(product[u])%MOD;
    ans%=MOD;
    
    mapy[x][y]=ans;
    mapy[y][x]=ans;
    printf("%lld\n", ans);
    }
    else
    {
    ans+=(mapy[u][v])%MOD;
    ans%=MOD;
    
    mapy[x][y]=ans;
    mapy[y][x]=ans;
    printf("%lld\n", ans);
    }
    }
  }  
}
}
