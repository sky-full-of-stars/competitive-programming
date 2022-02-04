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


const int maxN = 1e2 + 3;

vi gp[maxN];
int vis[maxN];
vpi nodes;

void insert(int a, int b)
{
	int n = sz(nodes);
	for (int i = 0; i < n; i++)
	{
		int c = nodes[i].ff, d = nodes[i].ss;
		if ((c < a and a < d) or (c < b and b < d))
		{
			//cerr << n + 1 << "  " << i + 1 << endl;
			gp[n + 1].pb(i + 1);
		}
		if ((a < c and  c < b) or (a < d and d < b))
		{
			//cerr << i + 1 << "  " << n + 1 << endl;
			gp[i + 1].pb(n + 1);
		}
	}
	nodes.push_back({a, b});

}

bool dfs(int src, int dest)
{
	vis[src] = 1;
	if (src == dest)
	{
		return true;
	}
	for (auto to : gp[src])
	{
		if (!vis[to])
		{
			//cerr << "moving from " << src << " to " << to << endl;
			if (dfs(to, dest))
				return true;
		}
	}

	//cerr << endl;
	return false;
}

string find(int a, int b)
{
	for (int i = 0; i < maxN; i++)
	{
		vis[i] = 0;
	}

	bool reachable = dfs(a, b);
	if (reachable)
	{
		return "YES";
	}
	return "NO";
}
void solve()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x, a, b;
		cin >> x >> a >> b;
		if (x == 1)
		{
			insert(a , b);
		}
		else
		{
			cout << find(a , b ) << endl;
		}
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