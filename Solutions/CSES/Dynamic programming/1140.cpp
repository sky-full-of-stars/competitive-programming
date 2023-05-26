#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include <bits/headerfile.hpp>
#else
#define dbg (...)
#endif

//---------------------------------------------------------------------------------------------------------//
using namespace std;

#define ll long long int
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
typedef pair<int, pair<int, int>> triplet;

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


const int maxN = 2 * 1e5 + 2;
/*
	time
		n ≤ 2⋅1e5
		n^2 -> 1e10
		if 1 sec is 1e8 operations
		1e10 code wont pass

		so do nlogn now
		1e5 * 16 -> works

	memory:
		dp[n]
		2*1e5 long long
		2*1e5 * 8  bytes
		16 * 1e5 bytes
		1.6 * 1e6 bytes
		1.6 mb
		works

		dp[n][n]
		2*1e10*8 -> 16 * 1e4 * 1e6 -. 16*1e4 mb > 512 mb
		so not possible

	so has to be 1d dp with n logn solution
	so has to be binary search over n elements
*/

int getValidPrevIdx(vi &v, int start)
{
	auto itr = lower_bound(all(v), start);
	if (itr == v.begin())
		return 0;
	else
	{
		//cerr << "*" << start << " " << *itr << endl;
		itr--;
		return (itr - v.begin() + 1);
	}
}

void solve()
{
	int n; cin >> n;
	vector<triplet> v(n + 1);
	vi endTimes;
	for (int i = 1; i <= n; i++)
	{
		int s, e, r;
		cin >> s >> e >> r;
		v[i] = {e, {s, r}};

	}

	sort(all(v));
	for (auto i : v)
	{
		if (i.ff)
			endTimes.pb(i.ff);
	}

	//best reward we can get by only having first i elements.
	ll dp[n + 1];
	dp[0] = 0;
	dp[1] = v[1].second.second;

	for (int i = 2; i <= n; i++)
	{
		int indexOfValidElement = getValidPrevIdx(endTimes, v[i].second.first);
		ll choose = v[i].second.second + dp[indexOfValidElement];
		ll notChoose = dp[i - 1];
		// cerr << i << " " << indexOfValidElement << endl;
		// cerr << choose << " " << notChoose << endl;
		dp[i] = max(choose, notChoose);
	}
	cout << dp[n] << endl;
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