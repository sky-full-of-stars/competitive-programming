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

typedef vector<string> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef pair<pi, vi> ppivi;
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


const int N = 1e7;

void clear()
{

}

bool isValid(int i, int j, vector<vector<char>>& v, bool** &vis)
{
	int n = sz(v); int m = sz(v[0]);
	return (i >= 0 and i<n and j >= 0 and j < m and v[i][j] != '#' and !vis[i][j]);
}

map<pi, pi> parMp;

bool bfs(pi src, pi dest, vector<vector<char>>& v)
{
	const static int n = sz(v);
	const static int m = sz(v[0]);

	bool** vis = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		vis[i] = new bool[m];
		for (int j = 0; j < m; j++)
		{
			vis[i][j] = false;
		}
	}

	queue<pi> q;
	vi path;
	q.push(src);
	vis[src.ff][src.ss] = true;
	parMp[ {src.ff, src.ss}] = {src.ff, src.ss};

	while (!q.empty())
	{
		int sz = sz(q);

		for (int i = 0; i < sz; i++)
		{
			pi pos = q.front();
			q.pop();

			if (pos == dest)
			{
				return true;
			}

			if (isValid(pos.ff, pos.ss - 1, v, vis))
			{
				vis[pos.ff][pos.ss - 1] = true;
				parMp[ {pos.ff, pos.ss - 1}] = {pos.ff, pos.ss};
				q.push({pos.ff, pos.ss - 1});
			}

			if (isValid(pos.ff, pos.ss + 1, v, vis))
			{
				vis[pos.ff][pos.ss + 1] = true;
				parMp[ {pos.ff, pos.ss + 1}] = {pos.ff, pos.ss};
				q.push({pos.ff, pos.ss + 1});
			}

			if (isValid(pos.ff - 1, pos.ss, v, vis))
			{
				vis[pos.ff - 1][pos.ss] = true;
				parMp[ {pos.ff - 1, pos.ss}] = {pos.ff, pos.ss};
				q.push({pos.ff - 1, pos.ss});
			}

			if (isValid(pos.ff + 1, pos.ss, v, vis))
			{
				vis[pos.ff + 1][pos.ss] = true;
				parMp[ {pos.ff + 1 , pos.ss}] = {pos.ff, pos.ss};
				q.push({pos.ff + 1, pos.ss});
			}
		}
	}

	return false;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> ch(n, vector<char>(m, '-'));

	//char ch[n][m];
	pi src, dest;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ch[i][j];
			if (ch[i][j] == 'A')
			{
				src = {i, j};
			}
			if (ch[i][j] == 'B')
			{
				dest = {i, j};
			}
		}
	}

	map<pi, string> dir;
	dir[ {0, -1}] = "R";
	dir[ {0, +1}] = "L";
	dir[ { +1, 0}] = "U";
	dir[ { -1, 0}] = "D";

	bool res = bfs(src, dest, ch);
	if (res)
	{
		cout << "YES" << endl;
		vi path;
		pi child = dest;
		while (parMp[child] != child)
		{
			pi par = parMp[child];
			pi delta = {par.ff - child.ff, par.ss - child.ss};
			path.pb(dir[delta]);
			child = par;
		}
		reverse(all(path));
		cout << sz(path) << endl;
		for (auto i : path)
		{
			cout << i;
		}
		cout << endl;
	}
	else
	{
		cout << "NO" << endl;
		return;
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