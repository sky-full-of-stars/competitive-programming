#include "bits/stdc++.h"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunknown-pragmas"

using namespace std;

//---------------------------------------------------------------------------------------------------------//

#define int long long int
#define cont continue;
#define br  break;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'

//---------------------------------------------------------------------------------------------------------//
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;
//---------------------------------------------------------------------------------------------------------//

#define EPS 1e-9
#define INF 1e18
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979323846264;

#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//---------------------------------------------------------------------------------------------------------//
#define sz(a) (int)((a).size())
#define setbits(x) __builtin_popcountll(x)
#define present(c,x) ((c).find(x) != (c).end())

#define ipArr(a,n)   for(int i=0;i<n;i++)  cin>>a[i];
#define ipArr1(a,n)  for(int i=1;i<=n;i++) cin>>a[i];
#define opArr(arr,n) for(int i=0;i<n;i++)  cout<<arr[i]<<" "; cout<<endl;
#define opArr1(arr,n)for(int i=1;i<=n;i++) cout<<arr[i]<<" "; cout<<endl;

#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()
#define rall(a) a.rbegin(), a.rend()

int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
int min(int a, int b) {return (a < b) ? a : b;}
int max(int a, int b) {return (a > b) ? a : b;}
//---------------------------------------------------------------------------------------------------------//


const int N = 2e5 + 7;

void clear()
{

}

vector<int> gp[N];
vector<int> dist(N, INF);
vector<int> vis(N, false);

void dfs(int start, int par, int dis)
{
	vis[start] = true;
	dist[start] = dis;

	for (auto child : gp[start])
	{
		if (child != par and !vis[child])
		{
			dfs(child, start, dis + 1);
		}
	}
}
void solve()
{
	int n; cin >> n;
	if (n == 1)
	{
		cout << 0 << endl;
		return;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		//u++, v++;
		gp[u].pb(v);
		gp[v].pb(u);
	}

	int start = 1;
	dfs(start, 0, 0);
	int mxDist = -1;
	int leaf1 = -1;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] > mxDist)
		{
			mxDist = dist[i];
			leaf1 = i;
		}
	}

	vis.assign(n + 1, false);
	dist.assign(n + 1, INF);
	start = leaf1;
	dfs(start, 0, 0);

	mxDist = -1;
	int leaf2 = -1;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] > mxDist and i != leaf1)
		{
			mxDist = dist[i];
			leaf2 = i;
		}
	}

	//----------------------------------------we have 2 leaves now--------------------//
	vis.assign(n + 1, false);
	dist.assign(n + 1, INF);
	dfs(leaf1, 0, 0);
	vi distFromLeaf1;
	distFromLeaf1.pb(0);
	for (int i = 1; i <= n; i++)
	{
		distFromLeaf1.pb(dist[i]);
	}


	vis.assign(n + 1, false);
	dist.assign(n + 1, INF);
	dfs(leaf2, 0, 0);
	vi distFromLeaf2;
	distFromLeaf2.pb(0);
	for (int i = 1; i <= n; i++)
	{
		distFromLeaf2.pb(dist[i]);
	}

	//--------------------------------------now we have dist[node to leaves] ----------------//

	for (int i = 1; i <= n; i++)
	{
		cout << max(distFromLeaf1[i], distFromLeaf2[i]) << " ";
	}

	clear();
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