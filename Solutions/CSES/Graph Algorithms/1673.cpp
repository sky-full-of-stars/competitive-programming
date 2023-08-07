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
#define INF 1e17
#define NINF -1e17
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


const int N = 1e5 + 5;

void clear()
{

}

class edge
{
public:
	int u, v, w;
public:
	edge(int u, int v, int w)
	{
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

vector<edge> vv;
int n, m;
int dist[N];

//https://www.youtube.com/watch?v=2Epc8xZObIc&list=PL2S6Mj7iLqEjNVq0e-pZ9rSnpAacHzVm3&index=14
void bellmanFord()
{
	fill_n(dist, n + 1, INF);
	dist[1] = 0;

	for (int i = 1; i < n; i++)
	{
		for (auto edge : vv)
		{
			int u = edge.u;
			int v = edge.v;
			int w = edge.w;

			if (dist[u] == INF)
			{
				continue;
			}

			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;

				//Dont let any value be more negative than NINF in the first place
				dist[v] = max(dist[v], NINF);
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (auto edge : vv)
		{
			int u = edge.u;
			int v = edge.v;
			int w = edge.w;

			if (dist[u] == INF)
			{
				continue;
			}

			//just in case if dist[v] had become less than NINF, reset it to NINF.
			dist[v] = max(dist[v], NINF);

			if (dist[v] > (dist[u] + w))
			{
				//cerr << "neg cycle found" << endl;
				dist[v] = NINF;
			}
		}
	}

}
void solve()
{
	cin >> n >> m;
	bool positiveSelfLoopAtRoot = false;
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge curEdge(u, v, -w);
		if (u == 1 and v == 1 and w > 0)
		{
			positiveSelfLoopAtRoot = true;
		}
		vv.push_back(curEdge);
	}

	bellmanFord();

	if (positiveSelfLoopAtRoot)
	{
		cout << -1 << endl;
		return;
	}

	if (dist[n] == NINF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << (-dist[n]) << endl;
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