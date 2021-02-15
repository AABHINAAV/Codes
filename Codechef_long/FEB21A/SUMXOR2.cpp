// Problem Link - https://www.codechef.com/FEB21A/problems/SUMXOR2
//Username : arpit0891
/* By Arpit G. mishra */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
/*/---------------------------Defines----------------------/*/
#define ll 				long long int
#define ld				long double
//#define mod             1000000007
#define inf       	      1e18
#define endl			"\n"
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define F(i,a)          for(int i=0;i<(a);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}
/*/-----------------------Time---------------/*/
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
/*/-----------------------Modular Arithmetic---------------/*/

const ll MaxN=1<<19;
const ll M=998244353;
ll mod=998244353;
ll ws[MaxN];
ll inverse_fac[500005];
ll sexy[500005];
ll fac[500005];
ll gpa[1<<19], gpb[1<<19];
/* const int mod=1e9+7;
template<const int MOD>
struct modular_int{
	int x;
	static vector<int> inverse_list ;
	const static int inverse_limit;
	const static bool is_prime;
	modular_int(){
		x = 0;
	}
	template<typename T>  
	modular_int(const T z){
		x = (z%MOD);
		if (x < 0) x += MOD; 	
	}
	modular_int(const modular_int<MOD>* z){
		x = z->x;
	}
	modular_int(const modular_int<MOD>& z){
		x = z.x;
	}
	modular_int operator - (const modular_int<MOD>& m) const{
		modular_int<MOD> U;
		U.x = x - m.x;
		if (U.x < 0) U.x += MOD;
		return U;
	}
	modular_int operator + (const modular_int<MOD>& m) const{
		modular_int<MOD> U;
		U.x = x + m.x;
		if (U.x >= MOD) U.x -= MOD;
		return U;
	}
	modular_int& operator -= (const modular_int<MOD>& m){
		x -= m.x;
		if (x < 0) x += MOD;
		return *this;
	}	
	modular_int& operator += (const modular_int<MOD>& m){
		x += m.x;
		if (x >= MOD) x -= MOD;
		return *this;
	}	
	modular_int operator * (const modular_int<MOD>& m) const{
		modular_int<MOD> U;
		U.x = (x* 1ull * m.x) %MOD;
		return U;
	}
	modular_int& operator *= (const modular_int<MOD>& m){
		x = (x * 1ull * m.x)%MOD;
		return *this;
	}
	template<typename T>
	friend modular_int operator + (const T &l, const modular_int<MOD>& p){
		return (modular_int<MOD>(l) + p);
	}
	template<typename T>
	friend modular_int operator - (const T &l, const modular_int<MOD>& p){
		return (modular_int<MOD>(l) - p);
	}
	template<typename T>
	friend modular_int operator * (const T &l, const modular_int<MOD>& p){
		return (modular_int<MOD>(l) * p);
	}
	template<typename T>
	friend modular_int operator / (const T &l, const modular_int<MOD>& p){
		return (modular_int<MOD>(l) / p);
	}
 
	int value() const{
		return x;
	}
 
	modular_int operator ^ (const modular_int<MOD>& cpower) const{
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		int power = cpower.x;
 
		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		while( power > 0){
			if (power&1){
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
		}
		return ans;
	}
 
 
	modular_int operator ^ (long long power) const{
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		// Prime Mods
		if (power >= MOD && is_prime){
			power %= (MOD - 1);
		}
 
		while( power > 0){
			if (power&1){
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
 
		}
		return ans;
	}
 
	modular_int operator ^ (int power) const{
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		
		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		while( power > 0){
			if (power&1){
				ans *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
 
		}
		return ans;
	}
	
	template<typename T>
	modular_int& operator ^= (T power) {
		modular_int<MOD> res = (*this)^power;
		x = res.x;
		return *this;
	}
 
 
	template<typename T>
	modular_int pow(T x){
		return (*this)^x;
	}
 
	
	pair<long long,long long> gcd(const int a, const int b) const {
		if (b==0) return {1,0}; 
		pair<long long,long long> c = gcd(b , a%b);
		return { c.second , c.first - (a/b)*c.second}; 
	}
 
	inline void init_inverse_list() const {
		
		vector<int>& dp = modular_int<MOD>::inverse_list;
		dp.resize(modular_int<MOD>::inverse_limit + 1);
		int n = modular_int<MOD>::inverse_limit;
		dp[0] = 1;
		if (n > 1) dp[1] = 1;
		for(int i = 2; i <= n; ++i){
			dp[i] = (dp[MOD%i] * 1ull *(MOD - MOD/i))%MOD;
		}
	
	}
	modular_int<MOD> get_inv() const {
		if (modular_int<MOD>::inverse_list.size() < modular_int<MOD>::inverse_limit + 1) init_inverse_list();
 
		if (this->x <= modular_int<MOD>::inverse_limit){
			return modular_int<MOD>::inverse_list[this->x];
		}
		pair<long long,long long> G = gcd(this->x,MOD);
		return modular_int<MOD>(G.first);
	}
	modular_int<MOD> operator - () const {
		modular_int<MOD> v(0);
		v -= (*this);
		return v;
	}
	modular_int operator / (const modular_int<MOD>& m) const{
		modular_int<MOD> U(this);
		U *= m.get_inv();
		return U;
	}
	modular_int& operator /= (const modular_int<MOD>& m){
		(*this) *= m.get_inv();
		return *this;
	}
	bool operator==(const modular_int<MOD>& m) const{
		return x == m.x;
	}
 
	bool operator < (const modular_int<MOD>& m) const {
		return x < m.x;
	}
 
 
	template<typename T>
	bool operator == (const T& m) const{
		return (*this)== (modular_int<MOD>(m));
	}
 
	template<typename T>
	bool operator < (const T& m) const {
		return x < (modular_int<MOD>(m)).x;
	}
	template<typename T>
	bool operator > (const T& m) const {
		return x > (modular_int<MOD>(m)).x;
	}
	template<typename T>
	friend bool operator == (const T& x, const modular_int<MOD>& m) {
		return (modular_int<MOD>(x)).x == m.x;
	}
	template<typename T> 
	friend bool operator < (const T& x, const modular_int<MOD>& m){
		return (modular_int<MOD>(x)).x < m.x;
	}
	template<typename T> 
	friend bool operator > (const T& x, const modular_int<MOD>& m){
		return (modular_int<MOD>(x)).x > m.x;
	}
 
	friend istream& operator >> (istream& is, modular_int<MOD>& p){
		int64_t val;
		is >> val;
		p.x = (val%MOD);
		if (p.x < 0) p.x += MOD;
		return is;
	}
	friend ostream& operator << (ostream& os, const modular_int<MOD>& p) {return os<<p.x;}
 
 
 
};
 
 
 
using mint = modular_int<mod>;
template<const int MOD>
vector<int> modular_int<MOD>::inverse_list ;
template<const int MOD>
const int modular_int<MOD>::inverse_limit = -1;
template<const int MOD>
const bool modular_int<MOD>::is_prime = true; */
// template<>   //-> useful if computing inverse fact = i_f[i-1] / i;
// const int modular_int<mod>::inverse_limit = 100000;


/*/---------------------------Graph---------------------/*/
template<typename T>
class Graph {
	int v;
	list<int> *adj;

public:
	Graph(int v) {
		this->v = v;
		adj = new list<int>[v];
	}

	void addEdge(int u, int v, bool bidir = true) {
		adj[u].push_back(v);
		if(bidir) {
			adj[v].push_back(u);
		}
	}

	void printAdjList() {
		for(int i=0;i<this->v;i++) {
			cout<<i<<"->";
			for(int node:adj[i]) {
				cout<<node<<", ";
			}
			cout<<endl;
		}
	}

	void bfs(int src) {
		queue<int> q;
		bool *visited = new bool[this->v+1]{0};

		q.push(src);
		visited[src] = true;

		while(!q.empty()) {
			int node = q.front();
			cout<<node<<" ";
			q.pop();
			for(int neighbour: adj[node]) {
				if(!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}

		delete [] visited;
	}


	void bfs(int src,int dest){
     	//Traverse all the nodes of the graph
     	queue<int> q;
     	bool *visited = new bool[v+1]{0};
     	int *dist = new int[v+1]{0};
     	int *parent = new int[v+1];

     	for(int i=0;i<v;i++){
     		parent[i] = -1;
     	}

     	q.push(src);
     	visited[src] = true;



     	while(!q.empty()){
     		int node = q.front();
     		cout<<node<<" ";
     		q.pop();

     		for(int neighbour:adj[node]){
     			
     			if(!visited[neighbour]){
     				q.push(neighbour);
     				visited[neighbour] = true;
     				dist[neighbour] = dist[node]  + 1;
     				parent[neighbour] = node;
     			}
     		}
     	}
     	cout<<endl;
     	//Print the distances of every node from source
     	for(int i=0;i<v;i++){
     		//cout<<i<<"node having dist "<<dist[i]<<endl;
     	}

     	//cout<<"Shortest dist is "<<dist[dest]<<endl;
     	//cout<<"Shortest path is ";

     	int temp = dest;
     	while(temp!=-1){
     		cout<<temp<<"<--";
     		temp = parent[temp];
     	}
     }

     void dfsHelper(int src, map<int, bool> &visited) {
     	visited[src] = true;
     	cout<<src<<" ";
     	for(int neighbour : adj[src]) {
     		if(!visited[neighbour]) {
     			dfsHelper(neighbour, visited);
     		}
     	}
     }

     

     void dfs(int src) {
     	map<int, bool> visited;
     	dfsHelper(src, visited);
     }

     void dfsHelper2(int src, map<int, bool> &visited) {
     	visited[src] = true;
     	// cout<<src<<" ";
     	for(int neighbour : adj[src]) {
     		if(not visited[neighbour]) {
     			dfsHelper2(neighbour, visited);
     		}
     	}
     }

     int connectedComponents() {
     	map<int, bool> visited;
     	int component = 0;
     	for(int i=0;i<v;i++) {
     		int city = i;
     		if(!visited[i]) {
     			dfsHelper2(i, visited);
     			component++;
     		}
     	}
     	return component;
     }
};

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}


long long power(long long a, long long b=mod-2, long long m=mod) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void fourier(ll *a,ll n,ll f){
    ll i,j,k,m,u,v,w,wm;
    for(i=n>>1,j=1,k;j<n-1;j++){
        if(i>j)swap(a[i],a[j]);
        for(k=n>>1;k<=i;k>>=1)i^=k;i^=k;
    }
    for(m=2;m<=n;m<<=1)
        for(i=0,wm=power(3,f==1?(M-1)/m:(M-1)/m*(m-1),M);i<n;i+=m)
            for(j=i,w=1;j<i+(m>>1);j++){
                u=a[j],v=1ll*w*a[j+(m>>1)]%M;
                if((a[j]=u+v)>=M)a[j]-=M;
                if((a[j+(m>>1)]=u-v)<0)a[j+(m>>1)]+=M;
                w=1ll*w*wm%M;
            }
    if(f==1)for(w=power(n,M-2,M),i=0;i<n;i++)a[i]=1ll*a[i]*w%M;
}
void fourier(ll *a,ll n){
    ll i,j,k,m,u,v,w,wm;
    ll f=0;
    for(i=n>>1,j=1,k;j<n-1;j++){
        if(i>j)swap(a[i],a[j]);
        for(k=n>>1;k<=i;k>>=1)i^=k;i^=k;
    }
    for(m=2;m<=n;m<<=1)
        for(i=0,wm=power(3,f==1?(M-1)/m:(M-1)/m*(m-1),M);i<n;i+=m)
            for(j=i,w=1;j<i+(m>>1);j++){
                u=a[j],v=1ll*w*a[j+(m>>1)]%M;
                if((a[j]=u+v)>=M)a[j]-=M;
                if((a[j+(m>>1)]=u-v)<0)a[j+(m>>1)]+=M;
                w=1ll*w*wm%M;
            }
    if(f==1)for(w=power(n,M-2,M),i=0;i<n;i++)a[i]=1ll*a[i]*w%M;
}
vector<ll> mul(vector<ll> arr,vector<ll> brr){
    ll n_a=arr.size()-1;
    ll n_b=brr.size()-1;
    ll n_final=1;
    while(n_final<=n_a+n_b)n_final*=2;
    ll i = 0;
    while(i<n_final){
        gpa[i] = i<=n_a?arr[i]:0;
        i++;
    }
    i=0;
    while(i<n_final){
        gpb[i] = i<=n_b?brr[i]:0;
        i++;
    }
    fourier(gpb, n_final);
    fourier(gpa, n_final);
    i=0;
    while(i<n_final){
        gpa[i]=gpa[i]*gpb[i]%M;
        i++;
    }
    fourier(gpa,n_final,1);
    vector<ll> c;
    i=0;
    while(i<=(n_a+n_b)){
        c.push_back(gpa[i]);
        i++;
    }
    return c;
}
ll nCr(ll n, ll r){
    if(r>n)return 0;
    return (((inverse_fac[r]*inverse_fac[n-r])%mod)*fac[n])%mod;
}
void fun(){
    inverse_fac[1]=inverse_fac[0]=1;
    sexy[1]=sexy[0]=1;
    fac[1]=fac[0]=1;
    for(ll i=2;i<200005;i++){
        sexy[i] = sexy[mod%i]*(mod-mod/i)%mod;
    }
    for(ll i=2;i<200005;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    for(ll i=2;i<200005;i++){
        inverse_fac[i]=(sexy[i]*inverse_fac[i-1])%mod;
    }
}
void solve()  {
    fun();
    ll n;
    scanf("%lld",&n);
    vector<ll> arr(n);
    vector<ll> sexy(30);
    for(ll i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<30;j++){
            if(arr[i]&(1<<j)){
                sexy[j]++;
            }
        }
    }
    vector<ll> sol(n+1);
    for(ll ii=0;ii<30;ii++){
        vector<ll> eno={0};
        vector<ll> orez={1};
        for(ll i=1;i<=sexy[ii];i+=2){
            eno.push_back(nCr(sexy[ii], i));
            eno.push_back(0);
        }
        ll i=1;
        while(i<=(n-sexy[ii])){
            orez.push_back(nCr(n-sexy[ii], i));;
            i++;
        }
        auto gotit=mul(eno, orez);
        i=0;
        while(i<=n){
            sol[i]=(sol[i]+((1<<ii)*gotit[i]))%mod;;
            i++;
        }
    }
    ll i=1;
    while(i<=n){
        sol[i]+=sol[i-1];
        sol[i]%=mod;
        i++;    
    }
    ll q;
    scanf("%lld",&q);
    while(q--){
        ll g;
        scanf("%lld",&g);
        printf("%lld\n",sol[g]);
    }
    }
int main() {
	clock_t begin = clock();
	file_i_o();
	int t=1;
	//cin>>t;
	while (t--){
		solve();
		//cout<<"\n";
		}
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
