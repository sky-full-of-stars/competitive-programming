#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include <bits/headerfile.hpp>
#else
#define dbg (...)
#endif

//---------------------------------------------------------------------------------------------------------//
using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define endl '\n'

//---------------------------------------------------------------------------------------------------------//
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;
typedef unordered_map<int, int> umi;

//---------------------------------------------------------------------------------------------------------//
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;
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
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }
#else
#define debug(...) 1
#define cerr if(0) cerr
#endif

//---------------------------------------------------------------------------------------------------------//
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ipArr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define opArr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()

int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
bool isPowOfTwo(int x) {return (x && (!(x & (x - 1))));}
//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;
int max(int a, int b)
{
	return a >= b ? a : b;
}

int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp) {
	if (target == 0)
		return 1;

	if (ind == 0)
		return arr[0] == target;

	if (dp[ind][target] != -1)
		return dp[ind][target];

	int notTaken = findWaysUtil(ind - 1, target, arr, dp);

	int taken = 0;
	if (arr[ind] <= target)
		taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

	return dp[ind][target] = notTaken + taken;
}

int findWays(vector<int> &num, int k) {
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(k + 1, -1));
	int x = findWaysUtil(n - 1, k, num, dp);
	int ans = 0;
	for (int i = 0; i <= k; i++)
	{
		ans += dp[n - 1][i];
	}
	return ans;
}

int ways(int x)
{
	vi v;
	int i = 1;
	v.pb(i);
	while (i * 2 <= x)
	{
		v.pb(i * 2);
		i *= 2;
	}
	return findWays(v, i);

}
void solve()
{
	int n, k; cin >> n >> k;

	int x = 0;
	int ans = 1;
	while (x < k)
	{
		int sumSoFar = (int)pow(2, x + 1) - 1;
		if ( sumSoFar <= n)
		{
			x++;
		}
		else
		{
			break;
		}
	}

	int way = 0;
	if (k > x)
	{
		int rem = (n - (int)pow(2, x));
		way = ways(rem);
	}

	ans = (int)pow(2, x) + way;
	cout << ans << endl;

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