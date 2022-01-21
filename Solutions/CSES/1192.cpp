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
}

const int gp_size = (int)1e6 + 7;
vi gp[gp_size];
int cnt[gp_size];

char arr[1001][1001];
int vis[1001][1001];
int cc;

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;

bool isValid(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
	{
		return false;
	}
	if (vis[x][y] || arr[x][y] == '#')
	{
		return false;
	}
	return true;
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (isValid(nextX, nextY))
		{
			dfs(nextX, nextY);
		}
	}
}

void solve()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == '.' && !vis[i][j])
			{
				dfs(i, j);
				cc++;
			}
		}
	}

	cout << cc << endl;

}


int32_t main()
{
	fio();
	return solve(), 0;
}
