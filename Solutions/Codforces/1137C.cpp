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
#define EPS (int)1e-9
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

const int maxN = 2 * 1e5 + 5;
const int gp_size = maxN;
vi gp[gp_size];
vi level(maxN, -1);
vi subTreeSz(maxN);

void dfs(int node, int lev)
{
	level[node] = lev;
	int treeSize = 0;
	for (int child : gp[node])
	{
		if (level[child] != -1)	// already visited
			cont;
		dfs(child, lev + 1);
		treeSize += subTreeSz[child];
	}

	subTreeSz[node] = 1 + treeSize;
}


void solve()
{
	int n, k, _n, u, v;
	read(n, k);
	_n = n - 1;

	while (_n--)
	{
		read(u, v);
		gp[u].pb(v);
		gp[v].pb(u);
	}

	dfs(1, 0);

	vi happiness(n + 1);
	//happiness[0] = EPS; //so that 0 is never selected

	for (int i = 1; i <= n; i++)
	{
		happiness[i] = level[i] - subTreeSz[i] + 1;
	}

	sort(happiness.begin() + 1, happiness.end(), greater<int>()); // dont select or sort 0th node.

	// for (int i = 1; i <= n; i++)
	// 	cerr << i << " " << level[i] << " " << subTreeSz[i] << " " << happiness[i] << endl;

	// for (int i : happiness)
	// 	cerr << i << " ";

	//choose k industriies with max happiness
	int ans = 0;
	for (int i = 1; i <= k; i++)
		ans += happiness[i];

	cout << ans << endl;

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
