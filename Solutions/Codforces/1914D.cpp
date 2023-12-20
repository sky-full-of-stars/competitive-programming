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
// int max(int a, int b) {return (a > b) ? a : b;}
//---------------------------------------------------------------------------------------------------------//


const int N = 1e7;

int max1, max2, max3;

vi getArr(vi& a)
{
	set<int> s1(all(a));
	auto it = s1.end();
	int reverse = min(3, sz(s1));
	advance(it, -reverse);
	int mx1 = *it;

	it++;
	int mx2 = -1;
	if (it != s1.end())
	{
		mx2 = *it;
	}

	it++;
	int mx3 = -1;
	if (it != s1.end())
	{
		mx3 = *it;
	}

	// debug(mx1);
	// debug(mx2);
	// debug(mx3);

	vi a1;
	if (mx3 != -1)
	{
		for (int i = 0; i < sz(a); i++)
		{
			if (a[i] == mx3)
				a1.pb(i);
		}
	}

	if (mx2 != -1)
	{
		for (int i = 0; i < sz(a); i++)
		{
			if (a[i] == mx2)
				a1.pb(i);
		}
	}

	if (mx1 != -1)
	{
		for (int i = 0; i < sz(a); i++)
		{
			if (a[i] == mx1)
				a1.pb(i);
		}
	}

	return a1;
}
int getRes(vi &a, vi &b, vi&c, vi& a1, vi &b1, vi &c1)
{
	int aday = a1[0];
	int bday, cday;
	for (auto i : b1)
	{
		if (i != aday)
		{
			bday = i;
			break;
		}
	}
	for (auto i : c1)
	{
		if (i != aday and i != bday)
		{
			cday = i;
			break;
		}
	}
	int ans1 = a[aday] + b[bday] + c[cday];

	bday = -1, cday = -1;
	for (auto i : c1)
	{
		if (i != aday)
		{
			cday = i;
			break;
		}
	}
	for (auto i : b1)
	{
		if (i != aday and i != cday)
		{
			bday = i;
			break;
		}
	}
	int ans2 = a[aday] + b[bday] + c[cday];

	return max(ans1, ans2);
}
void solve()
{
	int n; cin >> n;
	vi a(n); ipArr(a, n);
	vi b(n); ipArr(b, n);
	vi c(n); ipArr(c, n);

	vi a1 = getArr(a);
	vi b1 = getArr(b);
	vi c1 = getArr(c);
	// debug(a1)
	// debug(b1)
	// debug(c1)

	int x = getRes(a, b, c, a1, b1, c1);
	int y = getRes(b, a, c, b1, a1, c1);
	int z = getRes(c, a, b, c1, a1, b1);

	cout << max({x, y, z}) << endl;

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