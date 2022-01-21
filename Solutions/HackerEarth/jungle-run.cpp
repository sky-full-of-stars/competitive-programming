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
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#else
#define cerr if(0) cerr
#endif
}

const int gp_size = (int)1e6 + 7;
vi gp[gp_size];
int cnt[gp_size];

//grids
int n;
char arr[31][31];
int vis[31][31];
int dis[31][31];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isValid(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	if (vis[x][y])
		return false;
	if (arr[x][y] == 'T')
		return false;
	return true;
}

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = 1;
	dis[x][y] = 0;
	while (!q.empty())
	{
		int curx = q.front().ff;
		int cury = q.front().ss;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int newX = curx + dx[i];
			int newY = cury + dy[i];
			if (isValid(newX, newY))
			{
				q.push({newX, newY});
				vis[newX][newY] = 1;
				dis[newX][newY] = dis[curx][cury] + 1;
				deb(newX, newY, dis[newX][newY])
				if (arr[newX][newY] == 'E')
					return dis[newX][newY];
			}
		}
	}
	return -1;
}
void solve()
{
	cin >> n;
	int sx, sy;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
		}
	}

	cout << bfs(sx, sy) << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
}

int32_t main()
{
	fio();
	return solve(), 0;
}
