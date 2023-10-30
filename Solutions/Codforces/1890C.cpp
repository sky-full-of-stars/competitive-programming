#include "bits/stdc++.h"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
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


vi v;
int f = 0;
int l = 0;

void clear()
{
	v.clear();
	f = 0;
	l = 0;
}

bool possible(string s, int cnt)
{
	debug(s);
	if (cnt < 0)
	{
		return false;
	}

	int n = s.size();
	int st = 0;
	while (st < n / 2 and s[st] == s[n - 1 - st])
	{
		s[st] = '';
		s[n - 1 - st] = '';
		st++;
	}

	s.erase(0, s.find_first_not_of("\t\n\v\f\r ")); // left trim
	s.erase(s.find_last_not_of("\t\n\v\f\r ") + 1); // right trim

	if (sz(s) == 0)
	{
		return true;
	}


	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] != s[n - 1 - i])
		{
			cerr << "1";
			int remchars = (n - i - 2);
			if (remchars == 0)
			{
				return true;
			}
			else
			{
				string _s = s.substr(i + 1, n - i - 1);
				return possible(_s, cnt);
			}
		}
		else
		{
			char cur = s[i];
			if (s[i] == '0')
			{
				s = s + "01";
				debug(s);
				v.pb(n - i + 1);
				string _s = s.substr(1, sz(s) - 2);
				debug(_s);
				return possible(_s, cnt - 1);
			}
			else
			{

				s = "01" + s;
				v.pb(i + 1);
				string _s = s.substr(1, sz(s) - 2);
				return possible(_s, cnt - 1);
			}
		}
	}
}

void solve()
{
	int n; cin >> n;
	string s; cin >> s;

	if (n & 1)
	{
		cout << -1 << endl;
		return;
	}
	else
	{
		bool res = possible(s, 300);
		if (res)
		{
			cout << sz(v) << endl;
			for (auto i : v)
			{
				cout << i << " ";
			}
			cout << endl;
		}
		else
			cout << "-1" << endl;
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