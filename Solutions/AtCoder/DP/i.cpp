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

const int maxN = 1e7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];
vector<double> v(3000);

double prob(int i, int n) // need i heads in n coins
{

	if (n == i)
	{
		double temp = 1.0;
		for (int i = 1; i <= n; i++)
		{
			temp *= (double)v[i];
		}
		return temp;
	}
	if (i == 0)
	{
		double temp = 1.0;
		for (int i = 1; i <= n; i++)
		{
			temp = temp *= (1.0 - v[i]);
		}
		return temp;
	}
	double chooseN = v[i + 1] * prob(i - 1, n - 1) ;
	double dontChooseN = (1.0 - v[i + 1]) * prob(i , n - 1);

	return chooseN + dontChooseN;
}

void solveMemo()
{

	int n; cin >> n;

	for (int i = 1; i <= n; i++) cin >> v[i];

	double ans = 0;
	for (int i = (n + 1) / 2; i <= n; i++)
	{
		ans += prob(i, n); // get i heads in n coins
	}

	printf("%.10f\n", ans );
}

void solve()
{
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> v[i];


	double dp[n + 1][n + 1];

	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] * (1 - v[i - 1]);
		//cerr << i << " " << dp[i - 1][0] << " " << v[i - 1] << endl;
	}

	for (int coins = 1; coins <= n; coins++)
	{
		for (int heads = 1; heads <= coins; heads++)
		{
			// coins'th coin can be head or tail

			// is head -> a[coins-1]* dp[coins-1][heads-1]
			// is tail -> (1-a[coins-1])* dp[coins-1][heads]


			dp[coins][heads] = v[coins - 1] * dp[coins - 1][heads - 1] +
			                   (1 - v[coins - 1]) * dp[coins - 1][heads];
		}
	}

	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= n; j++)
	// 	{
	// 		printf("%.3f ", dp[i][j]);
	// 	}
	// 	cout << endl;
	// }

	double ans = 0;
	for (int heads = (n + 1) / 2; heads <= n ; heads++)
	{
		ans += dp[n][heads];
	}

	printf("%.12f\n", ans);

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
