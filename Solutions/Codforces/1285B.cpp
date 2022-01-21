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
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ipArr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define opArr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) (i.begin(),i.end())

//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

void solver()
{
	int n; cin >> n;

	vi v(n);
	int sum = 0;

	//bool allPositive = true;
	//bool allZero = true;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];

		// if (v[i] < 0)
		// 	allPositive = false;
		// if (v[i] != 0)
		// 	allZero = false;

		sum += v[i];
	}

	// if (allPositive and !allZero)
	// {
	// 	cout << "YES" << endl;
	// 	return;
	// }

	vi dp(n);
	fill_vec(dp, n, 0);

	dp[0] = (v[0] > 0) ? v[0] : 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] > 0)
		{
			dp[i] = dp[i - 1] + v[i];
		}
		else
		{
			dp[i] = max(dp[i - 1] + v[i], 0);
		}
	}

	int maxSum = 0;
	for (int i : dp)
	{
		maxSum = max(maxSum, i);
	}

	//debug(sum, maxSum);

	bool repMaxSum = false; //maxSum can be obtained with multiple segments
	int c = 0;
	for (int i : dp)
	{
		if (i == maxSum or i == 0)
			c++;
	}
	if (c > 1)
		repMaxSum = true;
	//debug(dp);
	//debug(repMaxSum);

	//sum == maxSum : full array is selected
	/*
		3
		6
		0 2 -1 3 -1 1
		6
		0 2 -1 3 -4 4
		6
		0 2 -1 3 -5 5
	*/

	if (sum > maxSum)
	{
		cout << "YES" << endl;
		return;
	}
	else if (sum < maxSum)
	{
		cout << "NO" << endl;
		return;
	}
	else if (sum == maxSum)
	{
		if (dp[n - 1] == maxSum and !repMaxSum)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	//cout << ((sum >= maxSum and !repMaxSum) ? "YES" : "NO") << endl;

}
void solve()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		solver();
	}
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
