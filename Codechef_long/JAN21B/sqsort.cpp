#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mpr make_pair
using namespace std;
const int N=1e4;
int n,b;
int c[N],d[N],w[N],inp[N];
int main()
{
    cin>>n>>b;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++)cin>>d[i];
    for(int i=0;i<b;i++)cin>>w[i];
    unordered_map<int,deque<int>>mp;
    unordered_map<int,int>h;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        for(int j=0;j<inp[i];j++){
            int y;cin>>y;
            mp[i+1].pb(y);
            h[y]=i+1;
        }
    }
    vector<pair<int,int>>op;
    string s;for(int i=0;i<n;i++)s+='S';
    int one=h[1];
    s[one-1]='Q';
    cout<<s<<endl;
    int buf1=1,buf2=2;
    if(one==1){
        buf1=3;
    }
    if(one==2){
        buf2=3;
    }
    while(mp[one].front()!=1){
        int tmp=mp[one].front();
        mp[one].pop_front();
        h[tmp]=buf1;
        mp[buf1].pb(tmp);
        op.pb(mpr(one,buf1));
    }
    int tmp=1;
    mp[one].pop_front();
    h[tmp]=buf2;
    mp[buf2].pb(tmp);
    op.pb(mpr(one,buf2));
    while(mp[one].size()!=0){
        tmp=mp[one].front();
        mp[one].pop_front();
        h[tmp]=buf1;
        mp[buf1].pb(tmp);
        op.pb(mpr(one,buf1));
    }
    tmp=1;
    mp[h[1]].pop_back();
    mp[one].pb(1);
    op.pb(mpr(buf2,one));
    for(int i=2;i<=b;i++){
        sort(inp,inp+N);
        while(mp[h[i]].back()!=i){
            tmp=mp[h[i]].back();
            mp[h[i]].pop_back();
            int buf=-1,val=INT_MAX;
            for(int j=1;j<=n;j++){
                if(j==one||j==h[i])
                    continue;
                if(mp[j].size()==0){
                    buf=j;
                    break;
                }
                int bk=mp[j].back();
                if(bk>tmp&&val>bk){
                    val=bk;
                    buf=j;
                }
            }
            if(buf==-1){
                for(int j=1;j<=n;j++){
                    if(j==one||j==h[i])
                        continue;
                    if(val>mp[j].size()){
                        val=mp[j].size();
                        buf=j;
                    }
                }
            }
            op.pb(mpr(h[i],buf));
            mp[buf].pb(tmp);
            h[tmp]=buf;
        }
        op.pb(mpr(h[i],one));
        tmp=mp[h[i]].back();
        mp[h[i]].pop_back();
        mp[one].pb(tmp);
        h[tmp]=one;
    }
    cout<<op.size()<<endl;
    for(int i=0;i<op.size();i++){
        cout<<op[i].ff<<" "<<op[i].ss<<endl;
    }
}