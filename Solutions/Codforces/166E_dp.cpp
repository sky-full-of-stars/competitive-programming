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


const int maxN = 1e7 + 2;

//int memo[2][maxN];
// void init()
// {
// 	for (int i = 0; i < 2; i++)
// 	{
// 		for (int j = 0; j < maxN; j++)
// 			memo[i][j] = -1;
// 	}
// }

// no clue why memoization fails for 1e7, anyway submitting for reference

// int numOfWaysMemo(int cur, int steps)
// {
// 	if (memo[cur][steps] != -1)
// 		return memo[cur][steps];

// 	if (cur == 1)
// 	{
// 		if (!steps)
// 			return memo[cur][steps] = 1;
// 		else
// 			return memo[cur][steps] = ((3 * numOfWaysMemo(0, steps - 1)) % mod);
// 	}
// 	else
// 	{
// 		if (!steps)
// 			return memo[cur][steps] = 0;
// 		else
// 			return memo[cur][steps] = ((2 * numOfWaysMemo(0, steps - 1)) % mod + (numOfWaysMemo(1, steps - 1)) % mod) % mod;
// 	}
// }

//https://www.youtube.com/watch?v=qQwQbD8ju2s
void solve()
{
	int steps; cin >> steps;
	//u->1
	//l->0
	//int cur = 1;
	//init();
	//cout << numOfWaysMemo(cur, steps);

	int dp[2][steps + 1];
	dp[0][0] = 0;
	dp[1][0] = 1;

	for (int i = 1; i <= steps; i++)
	{
		dp[1][i] = (3 * dp[0][i - 1]) % mod;

		int goSideChoice = (2 * dp[0][i - 1]) % mod;
		int goUpChoice = dp[1][i - 1];
		dp[0][i] = (goUpChoice + goSideChoice) % mod;
	}

	cout << dp[1][steps] << endl;
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
	int t = 1; //cin>>t;
	while (t--) solve();
	return 0;
}