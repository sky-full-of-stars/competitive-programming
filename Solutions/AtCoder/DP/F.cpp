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

const int maxN = 3e3 + 3;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

string a, b;
//int dp[maxN][maxN];

vector<char> common;

// int LCSmemo(int i, int j) // uses dp[][]
// {
// 	if (i == 0 or j == 0)
// 	{
// 		return 0;
// 	}
// 	if (dp[i][j] != 0)
// 	{
// 		return dp[i][j];
// 	}
// 	if (a[i - 1] == b[j - 1])
// 	{
// 		common.pb(a[i - 1]);
// 		// cerr << i << " " << j << " ";
// 		// cerr << a[i - 1] << " ";
// 		// cerr << endl;
// 		return dp[i][j] = 1 + LCSmemo(i - 1, j - 1);
// 	}
// 	else
// 	{
// 		return dp[i][j] = max( LCSmemo(i , j - 1), LCSmemo(i - 1, j) );
// 	}

// }

int LCS(int n, int m) // uses tab[][]
{
	int tab[maxN][maxN];

	memset(tab, 0, sizeof(tab));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				tab[i][j] = tab[i - 1][j - 1] + 1;
			}
			else
			{
				tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
			}
		}
	}

	int x = n, y = m;
	string ans = "";
	while (x > 0 and y > 0)
	{
		if (tab[x][y] == tab[x - 1][y])
		{
			x--;
		}
		else if (tab[x][y] == tab[x - 1][y])
		{
			y--;
		}
		else
		{
			ans = a[x - 1] + ans;
			x--;
			y--;
		}
	}
	cout << ans << endl;

	return tab[n][m];
}
// void print(int n, int m)
// {
// 	int x = n, y = m;
// 	string ans = "";
// 	while (x > 0 and y > 0)
// 	{
// 		if (tab[x][y] == tab[x - 1][y])
// 		{
// 			x--;
// 		}
// 		else if (tab[x][y] == tab[x - 1][y])
// 		{
// 			y--;
// 		}
// 		else
// 		{
// 			ans = a[x - 1] + ans;
// 			x--;
// 			y--;
// 		}
// 	}
// 	cout << ans << endl;
// 	return;
// }
void solve()
{
	cin >> a >> b;
	int n = a.length();
	int m = b.length();

	// MEMOIZATION
	//memset(dp, 0, sizeof(dp));
	//int len = LCSmemo(n, m);

	//TABULATION
	int len1 = LCS(n, m);
	//print(n, m);

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= m; j++)
	// 	{
	// 		cerr << dp[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }

	// cerr << endl << endl;

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= m; j++)
	// 	{
	// 		cerr << tab[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }


	//deb(len, len1);
}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
