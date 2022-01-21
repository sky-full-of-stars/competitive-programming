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
const int dx[6] = {1, 0, -1, 0, 0, 0}, dy[6] = {0, 1, 0, -1, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};

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

const int maxN = 13;
int n, m, k;
int x, y;

char gp[maxN][maxN][maxN];
bool vis[maxN][maxN][maxN];

bool valid(int z, int x, int y)
{
	if (x <= 0 or y <= 0)
		return false;
	if (x > n or y > m)
		return false;
	if (z<0 or z >= k)
		return false;
	return gp[z][x][y] != '#';
}
int filled;
void dfs(int plane, int x, int y)
{
	vis[plane][x][y] = 1;
	//deb(plane, x, y);
	filled ++;
	for (int i = 0; i < 6; i++)
	{
		int cx = x + dx[i];
		int cy = y + dy[i];
		int cPlane = plane + dz[i];

		if (valid(cPlane, cx, cy))
		{
			if (!vis[cPlane][cx][cy])
			{
				dfs(cPlane, cx, cy);
			}
		}
	}
}

void solve()
{
	cin >> k >> n >> m;

	for (int plate = 0; plate < k; plate++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> gp[plate][i][j];
			}
		}
	}

	cin >> x >> y;

	dfs(0, x, y);

	cout << filled << endl;
}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
