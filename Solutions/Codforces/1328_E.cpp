#include "bits/stdc++.h"

using namespace std;

#define int long long // −9·10^18 to 9·10^18
#define lll __int128_t //−10^38 to 10^38
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mi;

//const
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;

// inputs & output & debug
#define w(t) int t; cin>> t; while(t--)
#define cin2(x,y) int x,y; cin>>x>>y;
template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << " "), ...);
}

#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

//useful functions
//#define deb(x) cout<<#x<<": "<<x<<endl;
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define gcd(x,y) return __gcd(x,y);
#define sz(a) int((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
#define sortv(a) sort(a.begin(),a.end())


void fio()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Desktop/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Desktop/CP/output.txt", "w", stdout);
#endif
}

vi gp[200007];
int vis[200007];
int it[200007], ot[200007];
int etime;
map<int, int> itime_map; // intime,node
map<int, int> otime_map; // otime, node



void dfs(int s)
{
	if (!vis[s])
	{
		vis[s] = 1;
		it[s] = etime++;
	}
	for (int children : gp[s])
	{
		if (!vis[children])
			dfs(children);
	}
	ot[s] = etime++;
}
void compute(int s, int n)
{
	dfs(s);
	for (int i = 1; i <= n; i++)
		itime_map[it[i]] = i;
	for (int i = 1; i <= n; i++)
		otime_map[ot[i]] = i;
}
void insertNeighborsOfPathNode(int i, set<int> &s)
{
	for (int children :  gp[i])
	{
		s.insert(children);
	}
}
bool isInPath(int j, int i) // is j in path of (1 to i)
{
	return (it[j] < it[i] && ot[j] > ot[i]);
}
void query(vi &nodes, int n)
{
	int ans;
	for (int i : nodes)
	{
		set<int> goodInnodes;
		goodInnodes.insert(i);
		set<int> goodOutnodes;
		goodOutnodes.insert(i);
		ans = true;
		int intime = it[i];
		int outime = ot[i];
		auto ptr1 = itime_map.find(intime);
		auto ptr2 = otime_map.find(outime);
		for (auto i = itime_map.begin(); i != ptr1; i++)
		{
			goodInnodes.insert((*i).second);
		}
		for (auto i = next(ptr2, 1); i != otime_map.end(); i++)
		{
			goodOutnodes.insert((*i).second);
		}
		set<int> goodnodesInPath ;
		set_intersection(goodInnodes.begin(), goodInnodes.end(),
		                 goodOutnodes.begin(), goodOutnodes.end(),
		                 inserter(goodnodesInPath, goodnodesInPath.begin()));

		set<int> neigh;
		for (int i : goodnodesInPath)
		{
			for (int neib : gp[i])
				neigh.insert(neib);
		}
		goodnodesInPath.insert(neigh.begin(), neigh.end());
		for (int j : nodes)
		{
			if (goodnodesInPath.find(j) == goodnodesInPath.end())
			{
				ans = false; break;
			}
		}
		if (ans)
			break;
	}
	(ans == true) ? cout << "YES" << endl : cout << "NO" << endl;

}
void solve()
{
	cin2(n, m);
	int _n = n - 1;
	while (_n--)
	{
		cin2(s, d);
		gp[s].pb(d);
		gp[d].pb(s);
	}
	compute(1, n);
	while (m--)
	{
		vi nodes;
		w(t)
		{
			int x;
			cin >> x;
			nodes.pb(x);
		}
		query(nodes, n);
	}
}

int32_t main()
{
	fio();
	return solve(), 0;
}
