#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define mp make_pair
#define endl '\n'


typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

//const
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

// inputs & output & debug
#define w(t) int t; cin>> t; while(t--)

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << " "), ...);
}

#ifndef ONLINE_JUDGE
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define deb(...) 1
#define cerr if(0) cerr
#endif

//useful functions
//#define deb(x) cout<<#x<<": "<<x<<endl;
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define op_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())

void fio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#else
#define cerr if(0) cerr
#endif
}

const int maxN = 1e5 + 5;
const int gp_size = maxN;
vpi gp[gp_size];
bool vis[gp_size]; // can manipulate dist[]. dist[u] = -1 ->visited
int dist[gp_size];
int n, m, s, l;
int ans;
set< pair<pi, int> > onRoad; //{{u,v},delta} along u->v delta distance more from u


void init()
{
	for (int i = 1; i <= n + 3; i++)
	{
		dist[i] = INF;
	}
}

void dijkstra(int node)
{
	priority_queue<pi, vpi, greater<pi>> pq;
	pq.push({0, s});
	dist[s] = 0;

	while (!pq.empty())
	{
		auto [curdis, cur] = pq.top();
		pq.pop();

		if (curdis > dist[cur])
			continue;

		if (curdis == l)
			ans++;

		for (pi child : gp[cur])
		{
			int to = child.ff;
			int w = child.ss;

			if (dist[to] > dist[cur] + w)
			{
				dist[to] = dist[cur] + w;
				pq.push({dist[to], to});
			}
		}
	}
}

void dfs(int node)
{
	vis[node] = 1;
	for (pi child : gp[node])
	{
		int to = child.ff;
		int w = child.ss;

		if (dist[node] + w > l and dist[node] < l)
		{
			int delta = l - dist[node]; // delta length to be travelled from node (in u--->v)
			int deltadash = w - delta; // distance from other end
			//if (delta>0 and deltadash>0) // delta == 0 -> node can be reached with distance l. so dont consider
			//{
			if (dist[node] + delta <= dist[to] + deltadash) // make sure its shortest path to reach point on a road actually
			{
				if (onRoad.find({ {to, node}, deltadash }) == onRoad.end()) // check if other way preLaunchProdContract.setpoint is already added
				{
					onRoad.insert({{node, to}, delta});
				}
			}
			//}
		}
		if (!vis[to])
			dfs(to);
	}
}


void solve()
{
	read(n, m, s);
	while (m--)
	{
		int u, v, w;
		read(u, v, w);
		gp[u].pb({v, w});
		gp[v].pb({u, w});
	}
	read(l);

	init();

	dijkstra(s);

	// for (int i = 1; i <= n; i++)
	// 	cerr << dist[i] << " ";
	// cerr << endl << "__________________________" << endl;

	dfs(s);

	// for (auto i : onRoad)
	// 	cerr << i.ff.ff << "->" << i.ff.ss << "AT" << i.ss << endl;

	ans += onRoad.size();
	cout << ans << endl;

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
