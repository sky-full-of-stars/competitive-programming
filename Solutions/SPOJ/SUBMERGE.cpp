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
#define print_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"[i=n];
#define sortv(a) sort(a.begin(),a.end())


void fio()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#else
#define cerr if(0) cerr
#endif
}

const int gp_size = (int)1e6 + 7;
vi gp[gp_size];
int vis[gp_size];
int in[gp_size];
int lo[gp_size];
set<int> art_pts;
int timer;
int child_cnt;

void dfs(int node, int par)
{
	vis[node] = 1;
	in[node] = lo[node] = timer++;
	int child_cnt = 0;
	for (int to : gp[node])
	{
		if (to == par)
			continue;
		if (!vis[to])
		{
			dfs(to, node);
			lo[node] = min(lo[node], lo[to]);

			child_cnt++;
			if (lo[to] >= in[node] && par != -1)
				art_pts.insert(node);

		}
		else
		{
			// backedge
			lo[node] = min(lo[node], in[to]);
		}
	}
	if (par == -1 && child_cnt > 1)
		art_pts.insert(node);
}

void solve()
{

	while (true)
	{
		int n, m, a, b; cin >> n >> m;
		if (n == 0 && m == 0)
			return;
		for (int i = 1; i <= n; i++)
		{
			gp[i].clear();
			vis[i] = 0;
			in[i] = 0;
			lo[i] = 0;
		}
		art_pts.clear();
		timer = 1;
		while (m--)
		{
			cin >> a >> b; gp[a].pb(b); gp[b].pb(a);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				dfs(i, -1);
			}
		}
		cout << art_pts.size() << endl;

	}

}

int32_t main()
{
	fio();
	return solve(), 0;
}
