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
int _n;

//https://stackoverflow.com/a/29197805/7218818
int search(vector<pi> &array, int start_idx, int end_idx, int search_val)
{

	if ( start_idx == end_idx ) {
		if (start_idx == _n) {
			return -1;
		}
		return array[start_idx].ff <= search_val ? start_idx : -1;
	}

	int mid_idx = start_idx + (end_idx - start_idx) / 2;

	if ( search_val < array[mid_idx].ff )
		return search( array, start_idx, mid_idx, search_val );

	int ret = search( array, mid_idx + 1, end_idx, search_val );
	return ret == -1 ? mid_idx : ret;
}

int up_bound(vector<pi> &v, int x) {

	int ans = INT_MIN;

	int l = 0;
	int r = _n - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (v[mid].ff > x)
		{
			r = mid - 1;
		}
		else
		{
			ans = max(ans, mid);
			l = mid + 1;
		}
	}
	return ans;
}
void solve()
{
	int n, k;
	cin >> n >> k; _n = n;

	vector<pi> mv(n);
	for (int i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		mv[i] = { m, v};
	}

	sortv(mv);
	debug(mv);

	for (int i = 1; i < n; i++)
	{
		mv[i].ss += mv[i - 1].ss;
	}

	int ans = -1;

	for (int i = 0; i < n; i++)
	{
		int first = i;
		int m = mv[i].ff;
		int v = mv[i].ss;

		int best = m + k - 1;
		int lastFound = search(mv, 0, n, best);
		int bestV = mv[lastFound].ss;
		if (i != 0)
		{
			bestV -= mv[i - 1].ss;
		}

		ans = max(ans, bestV);


		if (mv[lastFound].ff == mv[i].ff) {
			i = lastFound;
		}

		debug(m, bestV);
	}

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
	int t = 1; //cin>>t;
	while (t--) solve();
	return 0;
}