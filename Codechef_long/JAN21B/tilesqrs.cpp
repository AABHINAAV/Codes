// Problem Link - https://www.codechef.com/JAN21B/problems/TILESQRS
//Username : arpit0891
/* By Arpit G. mishra */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
/*/---------------------------Defines----------------------/*/
#define ll 				long long int
#define ld				long double
#define mod             1000000007
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
#define fill(w,t)       memset(w,t,sizeof(w))
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define F(i,a)          for(int i=0;i<(a);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<"\n";	
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
// const ll mod=998244353 ;

const ll maxn = 1e6+1;

const ll llmax = (1ll<<60);

const int intmax = (1<<30);

//const ll PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899863;

vi fact , ifact;

vi primes;

vi spf;
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

 
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
		modular_int<MOD> output;
		output.x = 1;
		modular_int<MOD> curr(this);
		int power = cpower.x;
 
		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		while( power > 0){
			if (power&1){
				output *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
		}
		return output;
	}
 
 
	modular_int operator ^ (long long power) const{
		modular_int<MOD> output;
		output.x = 1;
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
				output *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
 
		}
		return output;
	}
 
	modular_int operator ^ (int power) const{
		modular_int<MOD> output;
		output.x = 1;
		modular_int<MOD> curr(this);
		
		if (curr.x <= 1){
			if (power == 0) curr.x = 1;
			return curr;
		}
		while( power > 0){
			if (power&1){
				output *= curr;
			}
			power >>= 1;
			if (power) curr *= curr;
 
		}
		return output;
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
const bool modular_int<MOD>::is_prime = 1; */
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

	void addEdge(int u, int v, bool bidir = 1) {
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
			cout<<"\n";
		}
	}

	void bfs(int src) {
		queue<int> q;
		bool *visited = new bool[this->v+1]{0};

		q.push(src);
		visited[src] = 1;

		while(!q.empty()) {
			int node = q.front();
			cout<<node<<" ";
			q.pop();
			for(int neighbour: adj[node]) {
				if(!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = 1;
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
     	visited[src] = 1;



     	while(!q.empty()){
     		int node = q.front();
     		cout<<node<<" ";
     		q.pop();

     		for(int neighbour:adj[node]){
     			
     			if(!visited[neighbour]){
     				q.push(neighbour);
     				visited[neighbour] = 1;
     				dist[neighbour] = dist[node]  + 1;
     				parent[neighbour] = node;
     			}
     		}
     	}
     	cout<<"\n";
     	//Print the distances of every node from source
     	for(int i=0;i<v;i++){
     		//cout<<i<<"node having dist "<<dist[i]<<"\n";
     	}

     	//cout<<"Shortest dist is "<<dist[dest]<<"\n";
     	//cout<<"Shortest path is ";

     	int temp = dest;
     	while(temp!=-1){
     		cout<<temp<<"<--";
     		temp = parent[temp];
     	}
     }

     void dfsHelper(int src, map<int, bool> &visited) {
     	visited[src] = 1;
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
     	visited[src] = 1;
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
	cout << *it << " = " << a << "\n";
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
int solve(){
  int n,q,k,r;
  cin>>n>>q>>k;
  int output[n][n];
  memset(output,-1,sizeof(output));
  cout<<1<<" "<<1<<" "<<1<<"\n";
  cout.flush();
  cin>>r;
  if(r==-1) return 0;
  if(r<k)
  {
    output[0][0]=1;
    output[0][1]=1;
    output[1][0]=1;
    output[1][1]=0;
  }
  else if(r>k)
  {
    output[0][0]=0;
    output[0][1]=1;
    output[1][0]=1;
    output[1][1]=0;
  }
  else
  {
    int c=0;
    int ri=0,ci=1;
    loop(i,0,3)
    {
      int rj=0,cj=2;
      loop(j,0,2)
      {
        k=r;
        cout<<1<<" "<<(rj%2)+1<<" "<<cj<<"\n";
        cout.flush();
        cin>>r;
        if(r==-1) return 0;
        if(r>k)
        {
          if(n==2)
          {
            c=1;
            output[0][0]=0;
            output[0][1]=1;
            output[1][0]=1;
            output[1][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<1<<"\n";
          cout.flush();
          cin>>r;
          if(r==-1) return 0;
          if(r<k)
          {
            c=1;
            output[0][0]=1;
            output[0][1]=1;
            output[1][0]=1;
            output[1][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<1<<"\n";
          cout.flush();
          cin>>r;
          if(r==-1) return 0;
        }
        rj++;
      }
        if(c) break;
        ri++;
        k=r;
        cout<<1<<" "<<(ri%2)+1<<" "<<ci<<"\n";
        cout.flush();
        cin>>r;
        if(r==-1) return 0;
        if(r>k)
        {
          if(n==2)
          {
            c=1;
            output[0][0]=0;
            output[0][1]=1;
            output[1][0]=1;
            output[1][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<1<<"\n";
          cout.flush();
          cin>>r;
          if(r==-1) return 0;
          if(r<k)
          {
            c=1;
            output[0][0]=1;
            output[0][1]=1;
            output[1][0]=1;
            output[1][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<1<<"\n";
          cout.flush();
          cin>>r;
          if(r==-1) return 0;
        }
    }
  }
  loop(i,2,n-1)
  {
      if(output[i-1][0]!=0)
       {
      k=r;
      cout<<1<<" "<<i<<" "<<1<<"\n";
      cout.flush();
      cin>>r;
      if(r==-1) return 0;
      output[i-1][0]^=1;
      if(r>k)
      {
        output[i][0]=1;
        output[i][1]=0;
      }
       }
       if(output[i-1][1]!=1)
       {
           k=r;
      cout<<1<<" "<<i<<" "<<2<<"\n";
      cout.flush();
      cin>>r;
      if(r==-1) return 0;
      output[i-1][1]^=1;
      if(r>k)
      {
        output[i][0]=1;
        output[i][1]=0;
      }
       }
       if(output[i][0]!=-1) continue;
      int cj=0;
      loop(j,0,3)
      {
        k=r;
        cout<<1<<" "<<i+1<<" "<<(cj%2)+1<<"\n";
        cout.flush();
        cin>>r;
        if(r==-1) return 0;

if(r>k)
        {
          k=r;
          cout<<1<<" "<<i<<" "<<1<<"\n";
          cout.flush();
          cin>>r;
          output[i-1][0]^=1;
          if(r==-1) return 0;
          if(r<k)
          {
            output[i][0]=1;
            output[i][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<i<<" "<<1<<"\n";
          cout.flush();
          cin>>r;
          output[i-1][0]^=1;
          if(r==-1) return 0;
        }
        cj++;
      }
  }
  loop(i,2,n-1)
  {
        if(output[0][i-1]!=0)
        {
      k=r;
      cout<<1<<" "<<1<<" "<<i<<"\n";
      cout.flush();
      cin>>r;
      if(r==-1) return 0;
      output[0][i-1]^=1;
      if(r>k)
      {
        output[0][i]=1;
        output[1][i]=0;
      }
        }
        if(output[1][i-1]!=1)
        {
            k=r;
      cout<<1<<" "<<2<<" "<<i<<"\n";
      cout.flush();
      cin>>r;
      if(r==-1) return 0;
      output[1][i-1]^=1;
      if(r>k)
      {
        output[0][i]=1;
        output[1][i]=0;
      }      
        }
        if(output[0][i]!=-1) continue;
      int rj=0;
      loop(j,0,3)
      {
        k=r;
        cout<<1<<" "<<(rj%2)+1<<" "<<i+1<<endl;
        cout.flush();
        cin>>r;
        if(r==-1) return 0;
        if(r>k)
        {
            k=r;
          cout<<1<<" "<<1<<" "<<i<<endl;
          cout.flush();
          cin>>r;
          output[0][i-1]^=1;
          if(r==-1) return 0;
          if(r<k)
          {
            output[0][i]=1;
            output[1][i]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<i<<endl;
          cout.flush();
          cin>>r;
          if(r==-1) return 0;
          output[0][i-1]^=1;
        }
        rj++;
      }
  }
  loop(i,2,n-1)
  {
    loop(j,2,n-1)
    {
      if(output[i-1][j-1]!=0)
      {
        k=r;
          cout<<1<<" "<<i<<" "<<j<<endl;
          cout.flush();
          cin>>r;
          if(r==-1) return 0;
          output[i-1][j-1]^=1;
      }
      if(output[i-1][j]!=1)
      {
        k=r;
        cout<<1<<" "<<i<<" "<<j+1<<endl;
          cout.flush();
          cin>>r;
          if(r==-1) return 0;
          output[i-1][j]^=1;
      }
      if(output[i][j-1]!=1)
      {
        k=r;
        cout<<1<<" "<<i+1<<" "<<j<<endl;
          cout.flush();
          cin>>r;
          if(r==-1) return 0;
          output[i][j-1]^=1;
      }
      
      k=r;
      cout<<1<<" "<<i+1<<" "<<j+1<<endl;
      cout.flush();
      cin>>r;
      if(r==-1) return 0;
      if(r>k)
      {
        output[i][j]=0;
      }
      else
      {
        output[i][j]=1;
      }
    }
  }
  cout<<2<<"\n";
  loop(i,0,n-1)
  {
    loop(j,0,n-1)
    {
      cout<<output[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout.flush();
  cin>>r;
  if(r==-1) return 0;
  return 1;
}

int main() {
	clock_t begin = clock();
	file_i_o();
	int t=1;
	cin>>t;
	while (t--){
		if (!solve()) break;
		//cout<<"\n";
		}
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}