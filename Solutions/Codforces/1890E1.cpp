#include "bits/stdc++.h"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunknown-pragmas"

using namespace std;

//---------------------------------------------------------------------------------------------------------//

#define int long long int
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


const int N = 1e7;

void clear()
{

}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<pi> v;
	for (int i = 1; i <= m; i++)
	{
		int l, r; cin >> l >> r;
		v.pb({l, r});
	}

	sortv(v);

	set<pi> rainStart;
	set<pi> rainEnd;
	mi rainOnThisDayAffectedHowManyCities;
	map<pi, int> rainCombinationDaysAffectedCityCnt;

	for (int i = 1; i <= m; i++)
	{
		int startCity = v[i - 1].first;
		rainStart.insert({startCity, i}); //mth day
	}

	int ans = 0;
	int cnt = 0;

	for (int city = 1; city <= n; city++)
	{
		while (!rainStart.empty())
		{
			auto front = *rainStart.begin();
			int lCity = front.first;
			int day = front.second;

			if (lCity > city)
			{
				break;
			}
			else
			{
				cnt++;
				rainStart.erase(front);
				int rcity;
				int idxInV = day - 1;
				rcity = v[idxInV].second;
				rainEnd.insert({rcity + 1, day});
			}
		}

		while (!rainEnd.empty())
		{
			auto front = *rainEnd.begin();
			int lCity = front.first;
			int day = front.second;

			if (lCity > city)
			{
				break;
			}
			else
			{
				cnt--;
				rainEnd.erase(front);
			}
		}

		debug(cnt);

		if (cnt == 0)
		{
			ans ++;
		}

		if (cnt == 1)
		{
			auto first = *rainEnd.begin();
			int day = first.second;
			rainOnThisDayAffectedHowManyCities[day]++;
		}

		if (cnt == 2)
		{
			auto firstDay = rainEnd.begin()->second;
			auto secondDay = (++rainEnd.begin())->second;
			rainCombinationDaysAffectedCityCnt[ {firstDay, secondDay}]++;
		}
	}


	int remove2RainsWithNonOverlappingCities = 0;
	vi values;
	for (auto [i, val] : rainOnThisDayAffectedHowManyCities)
	{
		values.pb(val);
	}
	sort(all(values), greater<int>());
	int consider = 2;
	for (auto i = values.begin(); i != values.end() and consider; i++)
	{
		remove2RainsWithNonOverlappingCities += *i;
		consider--;
	}

	debug(remove2RainsWithNonOverlappingCities);


	int mx = -1;
	for (auto [i, j] : rainCombinationDaysAffectedCityCnt)
	{
		int day1 = i.first;
		int day2 = i.second;
		mx = max(mx, rainOnThisDayAffectedHowManyCities[day1] +
		         rainOnThisDayAffectedHowManyCities[day2] +
		         j);
	}
	debug(rainCombinationDaysAffectedCityCnt);
	debug(mx);

	ans += max(mx, remove2RainsWithNonOverlappingCities);
	cout << ans << endl;

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