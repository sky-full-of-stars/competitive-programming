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
typedef pair<int, pair<int, int>> ppi;
typedef vector<pi> vpi;
typedef map<int, int> mi;
//---------------------------------------------------------------------------------------------------------//

#define EPS 1e-9
#define INF 1e18
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979323846264;

#define yes cout << "Yes" << endl
#define no cout << "No" << endl
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}}; //for (auto [dx,dy] : steps)
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


const int N = 1e3 + 2;
char v[N][N];
bool vis[N][N];
int timeAt[N][N];
map<pi, pi> par;
void clear()
{

}
bool valid(pi pos, int n, int m)
{
	return (pos.ff >= 0 and pos.ff < n
	        and pos.ss >= 0 and pos.ss < m
	        and (v[pos.ff][pos.ss] == '.' or v[pos.ff][pos.ss] == 'A')
	        and !vis[pos.ff][pos.ss]
	       );
}

bool valid(pi pos, int n, int m, int time)
{
	return (pos.ff >= 0 and pos.ff<n
	        and pos.ss >= 0 and pos.ss < m
	        and v[pos.ff][pos.ss] == '.'
	        and timeAt[pos.ff][pos.ss] > time
	       );
}

bool edge(pi pos, int n, int m)
{
	int x = pos.ff;
	int y = pos.ss;
	if (x == 0 or x == n - 1 or y == 0 or y == m - 1)
	{
		return true;
	}
	return false;
}
void solve()
{
	int n, m; cin >> n >> m;

	vpi init;
	pi you;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			timeAt[i][j] = 1002;
			if (v[i][j] == 'M')
			{
				init.pb({i, j});
			}
			else if (v[i][j] == 'A')
			{
				you = {i, j};
			}
		}
	}

	if (edge(you, n, m))
	{
		cout << "YES" << endl;
		cout << 0 << endl;
		return;
	}

	queue<ppi> q;
	for (auto i : init)
	{
		q.push({0, i});
		vis[i.ff][i.ss] = true;
		timeAt[i.ff][i.ss] = 0;
	}
	while (!q.empty())
	{
		ppi prevPos = q.front();
		q.pop();
		//pi curpos = {prevPos.ss.ff , prevPos.ss.ss};

		for (auto [dx, dy] : steps)
		{
			pi newPos = {prevPos.ss.ff + dx, prevPos.ss.ss + dy};

			if (valid(newPos, n, m))
			{
				vis[newPos.ff][newPos.ss] = true;
				q.push({prevPos.ff + 1, newPos});
				timeAt[newPos.ff][newPos.ss] = prevPos.ff + 1;
			}
		}
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout << timeAt[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	queue<ppi> qq;
	qq.push({0, you});
	pi dummy = { -1, -1};
	par[you] = dummy;

	map<pi, char> dir;
	dir[ {0, 1}] = 'R';
	dir[ {1, 0}] = 'D';
	dir[ {0, -1}] = 'L';
	dir[ { -1, 0}] = 'U';

	while (!qq.empty())
	{
		int time = qq.front().ff;
		pi cur = qq.front().ss;
		int curx = cur.ff;
		int cury = cur.ss;
		qq.pop();

		for (auto [dx, dy] : steps)
		{
			pi newPos = {curx + dx, cury + dy};

			if (valid(newPos, n, m, time + 1))
			{
				//debug(newPos);
				par[newPos] = cur;
				qq.push({time + 1, newPos});
				timeAt[newPos.ff][newPos.ss] = time + 1;
				if (edge(newPos, n, m))
				{
					cout << "YES" << endl;
					pi root = newPos;
					vector<char> path;
					while (par[root] != dummy)
					{
						pi dif = {root.ff - par[root].ff, root.ss - par[root].ss};
						path.pb(dir[dif]);
						root = par[root];
					}
					// pi dif = {root.ff - you.ff, root.ss - you.ss};
					// path.pb(dir[dif]);
					reverse(all(path));
					cout << sz(path) << endl;
					for (auto i : path)
					{
						cout << i;
					}
					cout << endl;
					return;
				}
			}
		}
	}

	cout << "NO" << endl;

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