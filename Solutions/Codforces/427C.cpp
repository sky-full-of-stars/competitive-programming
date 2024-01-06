#include "bits/stdc++.h"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;

//---------------------------------------------------------------------------------------------------------//

#define int long long int
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

void _print(bool t) {cerr << t;}
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
int ceil(int a, int b) {return (a + b - 1) / b;}
//---------------------------------------------------------------------------------------------------------//


const int N = 1e5 + 7;
vi gp[N];

/*
	src code ref: https://codeforces.com/contest/427/submission/23033640

	video's to understand:
	1) https://www.youtube.com/watch?v=o6N9qwizaTI
	2) https://www.youtube.com/watch?v=lrCVqsH3lVk
	3) https://youtu.be/qrAub5z8FeA?si=xfSkwYL8_5WXOyUo (to understand intution & lo array)
*/
struct Tarjan
{
	vector<int> inTime, lo;
	vector<vector<int>> sccs;
	vector<bool> onStack;
	stack<int> curDfsEleStk;
	vector<int>* adj;
	int time;

	void dfs(int u)
	{
		inTime[u] = time;
		lo[u] = time;
		time++;

		curDfsEleStk.push(u);
		onStack[u] = true;

		for (int v : gp[u])
		{
			if (inTime[v] == -1)
			{
				dfs(v);
				lo[u] = min(lo[u], lo[v]);
			}
			else // v is already visited
			{
				if (onStack[v]) //and v is also visited in current traversal
				{
					lo[u] = min(lo[u], inTime[v]);
				}
			}
		}

		if (inTime[u] == lo[u])
		{
			vector<int> curSccNodes;
			while (true)
			{
				int cur = curDfsEleStk.top();
				curDfsEleStk.pop();
				onStack[cur] = false;
				curSccNodes.pb(cur);
				if (cur == u) break;
			}
			sccs.pb(curSccNodes);
		}
	}

	vector<vi> computeSCC(int n, vector<int>* iadj)
	{
		inTime = vector<int>(n + 1, -1);
		lo = vector<int>(n + 1, -1);
		onStack = vector<bool>(n + 1, -1);
		curDfsEleStk = stack<int>();
		sccs.clear();
		adj = iadj;
		time = 0;

		for (int i = 1; i <= n; i++)
		{
			if (inTime[i] == -1) //not visited yet
			{
				dfs(i);
			}
		}
		return sccs;
	}
};

void getAns(vector<vi> &sccs, int &minCost, int &ways, vi &cost)
{
	for (auto scc : sccs)
	{
		int mn = INF;
		int freq = 0;
		for (auto node : scc)
		{
			if (cost[node] < mn)
			{
				mn = cost[node];
				freq = 1;
			}
			else if (cost[node] == mn)
			{
				freq++;
			}
		}
		minCost += mn;
		ways = (ways * freq) % MOD;
	}
}
void solve()
{
	int n; cin >> n;
	vi cost(n + 1);
	for (int i = 1; i <= n; i++) cin >> cost[i];

	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		gp[u].pb(v);
	}

	Tarjan trajan;
	vector<vi> sccs = trajan.computeSCC(n, gp);
	debug(sccs);

	int minCost = 0;
	int ways = 1ll;
	getAns(sccs, minCost, ways, cost);
	cout << minCost << " " << ways << endl;
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