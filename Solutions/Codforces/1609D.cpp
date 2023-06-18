#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include <bits/headerfile.hpp>
#else
#define dbg (...)
#endif

//---------------------------------------------------------------------------------------------------------//
using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define endl '\n'

//---------------------------------------------------------------------------------------------------------//
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;
typedef unordered_map<int, int> umi;

//---------------------------------------------------------------------------------------------------------//
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

//---------------------------------------------------------------------------------------------------------//
template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << " "), ...);
}

#ifndef ONLINE_JUDGE
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }
#else
#define debug(...) 1
#define cerr if(0) cerr
#endif

//---------------------------------------------------------------------------------------------------------//
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ipArr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define opArr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()

int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
bool isPowOfTwo(int x) {return (x && (!(x & (x - 1))));}
//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e3 + 3;

int par[maxN]; // keep track of parent
int siz[maxN]; // keep track of size

int n;
int mxSz = 1;
void init()// init with size arr and par arr
{
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
		siz[i] = 1;
	}
}

int root(int u) // path compression
{
	int rootU = u;
	while (par[rootU] != rootU)
	{
		rootU = par[par[rootU]];
	}
	return rootU;
}

bool find(int u, int v)
{
	return (root(u) == root(v));
}

int weightedUnion(int u, int v) // weighted union
{
	int rootU = root(u);
	int rootV = root(v);

	if (rootU == rootV)
	{
		return 1;
	}

	//cerr << rootU << " " << rootV << " " << siz[rootU] << " " << siz[rootV] << " " << endl;
	if (siz[rootU] <= siz[rootV])
	{
		par[rootU] = rootV;
		siz[rootV] += siz[rootU];
		siz[rootU] = 0;
	}
	else
	{
		par[rootV] = rootU;
		siz[rootU] += siz[rootV];
		siz[rootV] = 0;
	}
	return 0;
}

void solve()
{
	int q; cin >> n >> q;
	int u, v;
	init();
	int totExtras = 1;
	while (q--)
	{
		cin >> u >> v;
		int extra = weightedUnion(u, v);
		totExtras += extra;

		int sizes[n + 1];
		for (int i = 1; i <= n; i++)
		{
			sizes[i] = siz[i];
		}
		sort(sizes + 1, sizes + n + 1);

		int sum = 0;
		int cnt = 0;
		for (int i = n; i >= n - totExtras + 1; i--)
		{
			sum = sum + sizes[i];
		}

		cout << sum - 1 << endl;
	}
}
void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}
int32_t main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	setUpLocal();
	int t = 1; //cin>>t;
	while (t--) solve();
	return 0;
}