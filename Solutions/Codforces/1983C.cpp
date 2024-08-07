#include "bits/stdc++.h"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;

//---------------------------------------------------------------------------------------------------------//

#define int long long int
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

void _print(bool t) {cerr << t;}
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
int ceil(int a, int b) {return (a + b - 1) / b;}
//---------------------------------------------------------------------------------------------------------//


const int N = 1e7;

void clear()
{

}
vi a;
vi b;
vi c;
int need; int n;

int al, ar, bl, br, cl, cr;
bool possible(vi &av, vi &bv, vi &cv)
{
	int l = 0;
	int sum = 0;
	al = 0;
	while (l < n)
	{
		sum += av[l];
		if (sum >= need)
		{
			ar = l;
			l++;
			bl = l;
			break;
		}
		else
		{
			l++;
			bl = l;
		}
	}

	sum = 0;
	while (l < n)
	{
		sum += bv[l];
		if (sum >= need)
		{
			br = l;
			l++;
			cl = l;
			break;
		}
		l++;
		cl = l;
	}

	sum = 0;
	while (l < n)
	{
		sum += cv[l];
		if (sum >= need)
		{
			cr = l;
			l++;
			al++; ar++;
			bl++; br++;
			cl++; cr++;
			return true;
		}
		l++;
	}

	return false;
}

void solve()
{
	cin >> n;

	a.clear();
	b.clear();
	c.clear();
	al = -1; ar = -1;
	bl = -1; br = -1;
	cl = -1; cr = -1;


	a.resize(n); b.resize(n); c.resize(n);
	ipArr(a, n); ipArr(b, n); ipArr(c, n);

	int tot = accumulate(all(a), 0ll);
	//debug(tot)
	need = ceil(tot / 3.0);
	//debug(need);


	if (possible(a, b, c))
	{
		cout << al << " " << ar << " " << bl << " " << br << " " << cl << " " << cr << endl;
	}
	else if (possible(a, c, b))
	{
		cout << al << " " << ar << " " << cl << " " << cr << " " << bl << " " << br << endl;
	}
	else if (possible(b, a, c))
	{
		cout << bl << " " << br << " " << al << " " << ar << " " << cl << " " << cr << endl;
	}
	else if (possible(b, c, a))
	{
		cout << cl << " " << cr << " " << al << " " << ar << " " << bl << " " << br << endl;
	}
	else if (possible(c, a, b))
	{
		cout << bl << " " << br << " " << cl << " " << cr << " " << al << " " << ar << endl;
	}
	else if (possible(c, b, a))
	{
		cout << cl << " " << cr << " " << bl << " " << br << " " << al << " " << ar << endl;
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