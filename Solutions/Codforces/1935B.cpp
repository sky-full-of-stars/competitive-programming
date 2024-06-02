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


const int N = 1e5 + 5;
bool f[N];

void clear(int n)
{
	for (int i = 0; i <= n; i++)
	{
		f[i] = false;
	}
}

int findMex(vi &v)
{
	const int N = 1e5 + 5;
	bool ff[N] = {false};
	for (int i : v)
	{
		ff[i] = true;
	}

	int ansMex = 0;
	for (int i = 0; i <= sz(v) + 1; i++)
	{
		if (!ff[i])
		{
			ansMex = i; break;
		}
	}
	return ansMex;
}

void solve()
{
	int n; cin >> n;
	vi v(n); ipArr(v, n);


	for (int i : v)
	{
		f[i] = true;
	}

	int ansMex = 0;
	for (int i = 0; i <= n; i++)
	{
		if (!f[i])
		{
			ansMex = i; break;
		}
	}
	//debug(ansMex)

	if (ansMex == 0)
	{
		cout << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " " << i + 1 << endl;
		}
		clear(n); return;
	}

	bool count[ansMex];
	for (int i = 0; i < ansMex; i++)
	{
		count[i] = false;
	}

	int good = 0;
	for (int i = 0; i < n; i++)
	{
		int cur = v[i];
		if (cur < ansMex and count[cur] == false)
		{
			good++;
			count[cur] = true;
		}
		if (good == ansMex)
		{
			if (i ==  n - 1)
			{
				cout << -1 << endl;
				clear(n); return;
			}
			else
			{
				vector<int> sub_vector(v.begin() + i + 1, v.end());
				//debug(sub_vector)
				int temp = findMex(sub_vector);
				//debug(temp)
				if (temp == ansMex)
				{
					cout << 2 << endl;
					cout << 1 << " " << i + 1 << endl;
					cout << i + 2 << " " << n << endl;
					clear(n); return;
				}
				else
				{
					cout << -1 << endl;
					clear(n); return;
				}
			}
		}
	}

	clear(n);
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