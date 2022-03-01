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
vi l, r, u, d;
bool isPossibleToShiftL(string s)
{
	for (char c : s)
	{
		for (int i : l)
		{
			if (c - '0' == i)
				return false;
		}
	}
	return true;
}
bool isPossibleToShiftR(string s)
{
	for (char c : s)
	{
		for (int i : r)
		{
			if (c - '0' == i)
				return false;
		}
	}
	return true;
}
bool isPossibleToShiftU(string s)
{
	for (char c : s)
	{
		for (int i : u)
		{
			if (c - '0' == i)
				return false;
		}
	}
	return true;
}
bool isPossibleToShiftD(string s)
{
	for (char c : s)
	{
		for (int i : d)
		{
			if (c - '0' == i)
				return false;
		}
	}
	return true;
}

void solve()
{
	int n; cin >> n;
	string s; cin >> s;

	if ((s.find('0') != string::npos))
	{
		if ((s.find('1') != string::npos) or (s.find('2') != string::npos) or (s.find('3') != string::npos))
		{
			cout << "YES" << endl; return;
		}
		else
		{
			cout << "NO" << endl; return;
		}
	}

	l.pb(1); l.pb(4); l.pb(7); l.pb(0);
	r.pb(3); r.pb(6); r.pb(9); r.pb(0);
	u.pb(1); u.pb(2); u.pb(3);
	d.pb(7); d.pb(0); d.pb(9);

	// ans is no, if its possible to duplicate the move.
	// duplicate can be done by shifting entire image either l or r or u or d.
	// for that to happen either l or r or u or d should be completely free.

	if (isPossibleToShiftL(s) or isPossibleToShiftR(s) or  isPossibleToShiftU(s) or isPossibleToShiftD(s))
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

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