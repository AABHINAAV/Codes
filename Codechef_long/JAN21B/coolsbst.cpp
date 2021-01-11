// Problem Link - https://www.codechef.com/JAN21B/problems/COOLSBST
//Username : arpit0891
/* By Arpit G. mishra */
#pragma(OFAST)
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
using base = complex<double>;
/*/---------------------------Defines----------------------/*/
#define ll 				long long int
#define ld				long double
#define mod             998244353
#define pll             pair<ll,ll>
#define inf       	      1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define xmp 				first
#define pmp 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<(b);i++)
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
int l, r, a, b;const int N = 1e6 + 5;const int Q = 1e6 + 5;const int M = 1e6 + 5;ll all[N], odd[N], special[N];int n;ll onit[N], inv[N];int freq[M];ll ans[Q];ll cur = 0;
/*/-----------------------Modular Arithmetic---------------/*/
inline int64_t gg(int x, int y, int pow, int rotate) {
if (pow == 0) {
return 0;
}
int pp = 1 << (pow-1);
int seg = (x < pp) ? ((y < pp) ? 0 : 3) : ((y < pp) ? 1 : 2);
seg = (seg + rotate) & 3;
const int rotateDelta[4] = {3, 0, 0, 1};
int nx = x & (x ^ pp), ny = y & (y ^ pp);
int nrot = (rotate + rotateDelta[seg]) & 3;
int64_t sq = int64_t(1) << (2*pow - 2);
int64_t ans = seg * sq;
int64_t add = gg(nx, ny, pow-1, nrot);
ans += (seg == 1 || seg == 2) ? add : (sq - add - 1);
return ans;
}
struct Query
{
int l, r, idx;
int64_t ord;

inline void calcOrder() {
ord = gg(l, r, 21, 0);
}
}qr[Q];
inline bool operator<(const Query &a, const Query &b) {
return a.ord < b.ord;
}
ll modpow(ll a, ll b)  //a is base, b is exponent
{
if(b==0)
return 1;
if(b==1)
return a;
if(b%2 == 1)
return (modpow(a,b-1)*a)%mod;
ll q = modpow(a,b/2);
return (q*q)%mod;
}

ll C(ll n, ll r)
{
if(n < r or n < 0 or r < 0) return 0;
return (1LL* ( ( 1LL * onit[n] * inv[r]) % mod) * inv[n-r]) % mod;
}
bool comp(struct Query &d1, struct Query &d2)
{
int b1 = d1.l / 150;
int b2 = d2.l / 150;
if(b1 != b2)
return b1 < b2;
else
return (b1 & 1) ? d1.r < d2.r : d1.r > d2.r;
}
inline void lefty(int x, ll n)
{ 
//x++;
cur += C(n, x);
cur %= mod;
}
inline void LEFTY(int x, ll n)
{ 
//x++;
cur -= C(n, x); cur += mod;
cur %= mod;
}
inline void righty(int x, ll a)
{ 
cur *= 2; cur %= mod; //p2(C(x,a), a);
cur += (- C(x, a) + 1 + 2 * mod) % mod;
cur %= mod;
//p1(cur);
}
ll chut = modpow(2, mod - 2);
inline void RIGHTY(int x, ll a)
{ 
cur -= 1; cur %= mod;
cur += C(x, a); cur
+= mod;
cur %= mod;
cur *= chut; cur %= mod;
}
ll qq = 0;

int storing[N]; 

vector<ll> getf(int x) 
{ 
vector<ll> ret; 
while (x != 1) 
{ 
ret.push_back(storing[x]); 
x = x / storing[x]; 
} 
return ret; 
} 
ll exceeding(ll l, ll r) {
ll ans = r - l;
ans /= 2;
if(r % 2 != 0 || l % 2 != 0) ans += 1;
return ans;
}

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

modular_int operator ^ (const modular_int<MOD>& cmodpow) const{
modular_int<MOD> ans;
ans.x = 1;
modular_int<MOD> itis(this);
int modpow = cmodpow.x;

if (itis.x <= 1){
if (modpow == 0) itis.x = 1;
return itis;
}
while( modpow > 0){
if (modpow&1){
ans *= itis;
}
modpow >>= 1;
if (modpow) itis *= itis;
}
return ans;
}


modular_int operator ^ (long long modpow) const{
modular_int<MOD> ans;
ans.x = 1;
modular_int<MOD> itis(this);
if (itis.x <= 1){
if (modpow == 0) itis.x = 1;
return itis;
}
// Prime Mods
if (modpow >= MOD && is_prime){
modpow %= (MOD - 1);
}

while( modpow > 0){
if (modpow&1){
ans *= itis;
}
modpow >>= 1;
if (modpow) itis *= itis;

}
return ans;
}

modular_int operator ^ (int modpow) const{
modular_int<MOD> ans;
ans.x = 1;
modular_int<MOD> itis(this);

if (itis.x <= 1){
if (modpow == 0) itis.x = 1;
return itis;
}
while( modpow > 0){
if (modpow&1){
ans *= itis;
}
modpow >>= 1;
if (modpow) itis *= itis;

}
return ans;
}

template<typename T>
modular_int& operator ^= (T modpow) {
modular_int<MOD> res = (*this)^modpow;
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
const bool modular_int<MOD>::is_prime = true; 
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
map<pll, ll> mpp;
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
ll f(ll l, ll r, ll a, ll b) {
ll f1 = all[r] - all[l - 1], f2 = odd[r] - odd[l - 1];
ll x1 = exceeding(l, r), num = r - l + 1;
if(a > num) return 0;
ll x2 = num - x1 - special[r] + special[l - 1];
ll aa = ans[mpp[{num, b}]] - ans[mpp[{num, a}]] + mod + C(num, a); aa %= mod;
ll bb = ans[mpp[{x1, min(x1, b)}]] - ans[mpp[{x1, a}]] + mod  + C(x1, a); bb %= mod;//p1(bb);
ll c = (bb + C(x1, a - 1)) % mod; c -= C(x1, b); c += mod; c %= mod;//p1(c);
ll d = aa - C(num - 1, a - 1) + C(num - 1, b) + mod; d %= mod; d *= modpow(2, mod - 2); d %= mod;
d += C(num - 1, a - 1); d %= mod; d -= C(num - 1, b); d += mod; d %= mod;
ll e = bb - C(x1 - 1, a - 1) + C(x1 - 1, b) + mod; e %= mod; e *= modpow(2, mod - 2); e %= mod;
e += C(x1 - 1, a - 1); e %= mod; e -= C(x1 - 1, b); e += mod; e %= mod;
ll one = aa ;
one += mod; one %= mod;
ll two = one - (bb); 
two += mod; two %= mod;
ll four = (two - (x2 * (c) % mod) % mod + mod) % mod;
ll lol = ((f1 % mod) * (d % mod)) % mod;
ll rofl = lol - ((f2 % mod) * (e ) % mod) % mod;
rofl += mod; rofl %= mod;
ll ans = 0;
ans += one; ans %= mod; ans += two; ans %= mod;
ans += four; ans %= mod; ans += lol; ans %= mod;
ans += rofl; ans %= mod;
return ans;
}
vector<pair<pll, pll>> q;
int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();
storing[1] = 1; 
for (int i = 2; i < N; i++)  
storing[i] = i; 

for (int i = 4; i < N; i += 2) 
storing[i] = 2; 

for (int i = 3; i * i < N; i++) 
{ 
if (storing[i] == i) 
{ 
for (int j = i * i; j < N; j += i) 
if (storing[j] == j) 
storing[j] = i; 
} 
} 
onit[0]=1;
loop(i,1,N)
{
onit[i] = (1LL * i * onit[i-1]) % mod;
}
inv[N-1] = modpow(onit[N-1], mod-2);
for(int i = N-2; i >= 0; i--)
{
inv[i] = (1LL * (i+1) * inv[i+1]) % mod;
};
odd[0] = all[0] = special[0] = 0;
loop(i, 1, N) {
odd[i] = all[i] = special[i] = 0;
vi v = getf(i); 
map<ll, ll> m;
for(auto it: v) 
m[it]++;
for(auto it: m) {
if(it.xmp == 2) {
if(it.pmp > 1) special[i]++;
}
else {
all[i] += it.pmp; 
if(i & 1LL) odd[i] += it.pmp;
}
}
odd[i] += odd[i - 1]; all[i] += all[i - 1]; special[i] += special[i - 1];
}
int n;
cin>>n;
ll itis = 1;
set<pll> s;
loop(i, 1, n + 1) {
    cin>>l>>r>>a>>b;
int x1 = exceeding(l, r), num = r - l + 1;
int x2 = num - x1 - special[r] + special[l - 1];
q.pb({{l, r}, {a, b}});
s.insert({num, max(0, a)}); s.insert({num, b}); s.insert({x1, max(0, a)}); s.insert({x1, min(x1, b)});
}
ans[0] = 1;
for(auto i: s) {
if(i.pmp == 0) { mpp[i] = 0; continue;}
qr[itis].r = i.xmp; qr[itis].l = i.pmp; qr[itis].idx = itis;
mpp[i] = itis; itis++;
}
qq = itis - 1;
sort(qr + 1, qr + qq + 1, comp);
int l = 1, r = 1;// ans = 1;
cur = 1;
for(int i=1;i<=qq;i++)
{
while(l < qr[i].l) lefty(++l, r);
while(l > qr[i].l) LEFTY(l--, r);
while(r < qr[i].r) righty(r++, l);
while(r > qr[i].r) RIGHTY(--r, l);
ans[qr[i].idx] = cur;
}
loop(i, 1, qq + 1) ans[i]++;
loop(i,0,n) {
cout<<(f(q[i].xmp.xmp, q[i].xmp.pmp, q[i].pmp.xmp, q[i].pmp.pmp))<<"\n";
}

#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
return 0;
}
