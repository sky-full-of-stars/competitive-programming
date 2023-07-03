#include "bits/stdc++.h"
using namespace std;

//---------------------------------------------------------------------------------------------------------//

//#define int long long int
#define cont continue;
#define br  break;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'

//---------------------------------------------------------------------------------------------------------//
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;
//---------------------------------------------------------------------------------------------------------//

#define EPS 1e-9
#define INF 1e18
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979323846264;

#define yes cout << "Yes" << endl
#define no cout << "No" << endl
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

//---------------------------------------------------------------------------------------------------------//
template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << " "), ...);
}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//---------------------------------------------------------------------------------------------------------//
#define sz(a) (int)((a).size())
#define setbits(x) __builtin_popcountll(x)
#define present(c,x) ((c).find(x) != (c).end())

#define ipArr(a,n)   for(int i=0;i<n;i++)  cin>>a[i];
#define ipArr1(a,n)  for(int i=1;i<=n;i++) cin>>a[i];
#define opArr(arr,n) for(int i=0;i<n;i++)  cout<<arr[i]<<" "; cout<<endl;
#define opArr1(arr,n)for(int i=1;i<=n;i++) cout<<arr[i]<<" "; cout<<endl;

#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()
#define rall(a) a.rbegin(), a.rend()

int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
int min(int a, int b) {return (a < b) ? a : b;}
int max(int a, int b) {return (a > b) ? a : b;}
//---------------------------------------------------------------------------------------------------------//




int n, l, r, s;
vi consideredElements;
const int MX_SUM = ((500) * (501)) / 2;
int dp[501][MX_SUM + 1];
//500*500*500/2*4 bytes
//125 * 1e6* 2  bytes
//250 * 1e6 bytes
//250 mb
//perfect limit

void clear()
{
	consideredElements.clear();
}

bool create(int idx, int sum, int sz)
{
	if (sz == 0 and sum == 0)
	{
		return 1;
	}
	int mxSumPossible = (idx * (idx + 1)) / 2;
	if (idx == 0 or sz == 0 or sum == 0 or
	        sum > mxSumPossible or sz > idx)
	{
		return 0;
	}

	if (dp[sz][sum] != -1)
	{
		return dp[sz][sum];
	}

	bool exclude = create(idx - 1 , sum, sz);
	if (exclude)
	{
		return dp[sz][sum] = 1;
	}

	consideredElements.pb(idx);
	bool include = create(idx - 1, sum - idx, sz - 1);
	if (include)
	{
		return dp[sz][sum] = 1;
	}
	else
	{
		consideredElements.pop_back();
	}

	return dp[sz][sum] = 0;
}


void solve()
{
	read(n, l, r, s);
	int sz = r - l + 1;

	//1.2.3.....n
	//first k elements
	//1....k
	//k*(k+1)/2
	int mnSumPossible = (sz * (sz + 1)) / 2;
	//debug(mnSumPossible);
	if (s < mnSumPossible)
	{
		cout << -1 << endl;
		return;
	}

	//1.2.3.....n
	// last k elements
	// n-k+1...n -> (n)-(n+k-1)+1 elements -> k elements
	// [n(n+1)/2] - [(n-k)(n-k+1)/2]
	int mxSumPossible = (n * (n + 1)) / 2 - ((n - sz) * (n - sz + 1)) / 2;
	//debug(mxSumPossible);
	if (s > mxSumPossible)
	{
		cout << -1 << endl;
		return;
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < (n * (n + 1)) / 2 + 1; j++)
		{
			dp[i][j] = -1;
		}
	}
	int idx = n;
	bool possible = create(idx, s, sz);
	if (possible)
	{
		vi ans(n, 0);
		vector<bool> used(n + 1, 0);

		for (int i = l - 1; i < r; i++)
		{
			assert(consideredElements.size() != 0);
			int cur = consideredElements.back();
			consideredElements.pop_back();
			ans[i] = cur;
			used[cur] = true;
		}

		int lastUnUsed = 1;
		for (int i = 0; i < n; i++)
		{
			if (ans[i] != 0)
			{
				cout << ans[i] << " ";
				continue;
			}

			while (used[lastUnUsed])
			{
				lastUnUsed++;
			}

			ans[i] = lastUnUsed;
			cout << ans[i] << " ";
			used[lastUnUsed] = 1;
		}
		cout << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	clear();
}
void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}
int32_t main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	setUpLocal();
	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}