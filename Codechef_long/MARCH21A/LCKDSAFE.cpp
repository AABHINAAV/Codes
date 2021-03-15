// Problem Link - https://www.codechef.com/MARCH21A/problems/LCKDSAFE
//Username : arpit0891
/* By Arpit G. mishra */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
/*/---------------------------Defines----------------------/*/
#define ll 				long long int
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define N 1000005
#define sz(s) (int)s.size()
#define F(i,a)          for(int i=0;i<(a);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	

ll n;
vector<ll> v(N);
ll arr[N];
ll daam[N];

bool bot(ll j, ll k); 
ll papa[N];

void f()
{
  stack<ll> dq; papa[1] = 0;dq.push(1);for(int i = 2; i <= n; i++) {papa[i] = 0;while(sz(dq) and v[dq.top()] < v[i]) dq.pop();if(sz(dq)) papa[i] = dq.top();dq.push(i);}
}

vector<ll> t(N);

/*/-----------------------Time---------------/*/
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
/*/-----------------------Modular Arithmetic---------------/*/


 
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
void solve()  {
    }
int main(int argc, char const *argv[]) {
 ll tt=1;
   cin >> tt;
   while(tt --)
   {
      
       cin>>n;
       loop(i,1,n + 1)  cin>>v[i]; stack<pair<ll,ll>> dq;daam[1] = 0;arr[1] = (v[1] == 0) ? 1 : 0;if(v[1] == 0)dq.push({1, 1});else dq.push({1, 0});
       ll tot = (dq.top().second == 1);
       f();
       loop(i, 2, n + 1) {
             ll mn = i, j; daam[i] = 0; ll ans = 0;for(ll k = 0; k < 60; k++) {j = i - 1;while((bot(j,k) != bot(i,k)) and j > 0) {daam[j] += (1LL << k);j--;}mn = min(mn, j + 1);} //p1(tot);
             ll roast = papa[i];
             roast++;
             if(roast >= mn) 
             {
                   pair<ll,ll> x; 
                  while(sz(dq) and dq.top().first >= mn) { x = dq.top();dq.pop();if(x.second == 1) { if(sz(dq))tot -= x.first - dq.top().first;else tot -= x.first;} }if(sz(dq) and dq.top().first < (mn - 1)) {if(dq.top().second == 0) tot += mn - 1 - dq.top().first;
                   dq.push({mn - 1, dq.top().second ^ 1}); } else if(!sz(dq)) {dq.push({mn - 1, x.second});if(x.second) tot += mn - 1;}
                  ll mx = -1, o = v[i], a = v[i];for(ll j = i; j >= mn; j--) {mx = max(mx, v[j]);o |= v[j]; a &= v[j];if((o ^ a) >= mx) t[j] = 1;else t[j] = 0;} ll idx = mn;while(idx <= i and t[idx] == t[mn]) {idx++; }
                   idx--;
                   if(sz(dq) and dq.top().second == t[mn]) {dq.pop(); dq.push({idx, t[mn]});}else dq.push({idx, t[mn]});if(t[mn]) tot += idx - mn + 1;idx++;while(idx <= i) {ll cur = idx;
                    while(cur <= i and t[cur] == t[idx]) cur++;dq.push({cur - 1, t[idx]});if(t[idx]) tot += cur - idx;idx = cur; }arr[i] = arr[i - 1] + tot;continue;
             } 
             if(roast < mn) { 
                  ll lo = roast, hi = i, res = roast - 1;while(lo <= hi) {ll mid = lo + hi;mid /= 2;if(daam[mid] >= v[i]) {res = mid;lo = mid + 1;}else hi = mid - 1;}
                  pair<ll,ll> x;
                  while(sz(dq) and dq.top().first >= roast) {x = dq.top();dq.pop();if(x.second == 1) {if(sz(dq))tot -= x.first - dq.top().first;else tot -= x.first;}}if(sz(dq) and dq.top().first < roast - 1) {if(dq.top().second == 0) tot += roast - 1 - dq.top().first;dq.push({roast - 1, dq.top().second ^ 1});}
                  else if(!sz(dq)) { dq.push({roast - 1, x.second});if(x.second) tot += roast - 1;}if(res == roast - 1) {arr[i] = arr[i - 1] + tot;if(dq.top().second == 0) dq.pop();dq.push({i, 0});continue;}
                  if(sz(dq)) {  if(dq.top().second == 1) {dq.pop(); dq.push({res, 1});if(i != res) dq.push({i, 0});}else {dq.push({res, 1});if(i != res) dq.push({i, 0});}}else {
                  dq.push({res, 1}); if(i != res) dq.push({i, 0});}tot += res - roast + 1;
             }
             arr[i] = arr[i - 1] + tot;
        }
        cout<<arr[n]<<"\n";
   }
   return 0;
}
bool bot(ll j, ll k) 
{
    return ((v[j] & (1LL << k)));
}


