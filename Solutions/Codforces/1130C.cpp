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
//const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
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

const int maxN = 55;
int n;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

int gp[maxN][maxN];
int vis[maxN][maxN];

vpi sv;
vpi dv;

const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}}; //for (auto [dx,dy] : steps)

bool valid(int x, int y)
{
	if (x<1 or y<1 or x>n or y>n)
		return false;
	return true;
}

void dfs(int x, int y, int flag)
{
	vis[x][y] = 1;

	if (flag)
	{
		dv.pb({x, y});
	}
	else
	{
		sv.pb({x, y});
	}

	for (auto [dx, dy] : steps)
	{
		int cx = x + dx;
		int cy = y + dy;
		if (!vis[cx][cy] and valid(cx, cy))
		{
			dfs(cx, cy, flag);
		}
	}
}

int calcDist(pi s, pi d)
{
	int x1 = s.ff;
	int y1 = s.ss;
	int x2 = d.ff;
	int y2 = d.ss;

	int xdis = abs(x2 - x1);
	int ydis = abs(y2 - y1);

	return xdis * xdis + ydis * ydis;

}
void solve()
{
	cin >> n;

	int sx, sy; cin >> sx >> sy; // s is src
	int dx, dy; cin >> dx >> dy; // d is dest

	for (int i = 1; i <= n; i++)
	{
		string s; cin >> s;
		for (int j = 1; j <= n; j++)
		{
			cin >> s[j - 1];
		}
	}

	dfs(sx, sy, 0);
	dfs(dx, dy, 1);

	int ans = 0;

	for (auto start : sv)
	{
		for (auto end : dv)
		{
			ans = min(calcDist(start, end), ans);
		}
	}

	cout << ans << endl;


}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
