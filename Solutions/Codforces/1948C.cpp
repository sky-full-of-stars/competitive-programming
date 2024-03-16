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


const int N = 2e5 + 7;

int n;
char grid[2][N];
bool vis[2][N];
int dp[2][2][N];

void clear()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[0][i][j] = -1;
			dp[1][i][j] = -1;
			vis[i][j] = false;
		}
	}
}

bool valid(int x, int y)
{
	return x >= 0 and x <= 1 and y >= 0 and y < n and !vis[x][y];
}


int f(int mv, pi pos)
{
	if (dp[mv][pos.ff][pos.ss] != -1)
	{
		return dp[mv][pos.ff][pos.ss];
	}


	vis[pos.ff][pos.ss] = true;
	if (pos.ff == 1 and pos.ss == n - 1)
	{
		return dp[mv][pos.ff][pos.ss] = 1;
	}

	if (mv == 0)
	{
		bool possible = false;
		for (auto [dx, dy] : steps)
		{
			int nx = pos.ff + dx;
			int ny = pos.ss + dy;
			if (valid(nx, ny))
			{
				pi npos = {nx, ny};
				int can = f(1, npos);
				if (can == 1)
				{
					possible = true;
					return dp[mv][pos.ff][pos.ss] = 1;
				}
			}
		}
		if (!possible)
		{
			dp[mv][pos.ff][pos.ss] = 0;
		}
	}
	else
	{
		bool possible = false;
		int dy = (grid[pos.ff][pos.ss] == '>') ? 1 : -1;
		int nx = pos.ff;
		int ny = pos.ss + dy;
		pi npos = {nx, ny};
		if (valid(nx, ny) )
		{
			int can = f(0, npos);
			if (can == 1)
			{
				possible = true;
				return dp[mv][pos.ff][pos.ss] = 1;
			}
		}
		if (!possible)
		{
			dp[mv][pos.ff][pos.ss] = 0;
		}

	}
	vis[pos.ff][pos.ss] = false;
	return dp[mv][pos.ff][pos.ss] = 0;
	//return false;
}

void solve()
{
	cin >> n;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
			dp[0][i][j] = -1;
			dp[1][i][j] = -1;
		}
	}


	pi npos = {0, 0};
	int can = f(0, npos);
	//debug(can);

	if (can == 1) yes;
	else no;

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
	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}