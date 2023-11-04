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
	int n; cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		int ele; cin >> ele;
		bitset<20> b(ele);
		//debug(b.to_string());
		v.pb(b.to_string());
	}

	int ans[n + 2][22];

	for (int i = 19; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			if (j == n - 1)
			{
				ans[j][i] = v[j][i] == '0' ? 0 : 1;
			}
			else
			{
				if (v[j][i] == '0')
				{
					ans[j][i] = 0;
				}
				else
				{
					ans[j][i] = ans[j + 1][i] + 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cerr << ans[i][j];
		}
		cerr << endl;
	}

	int q; cin >> q;
	while (q--)
	{
		int l, k; cin >> l >> k;
		l--;

		map<int, vi> m;
		for (int j = 0; j < 20; j++)
		{
			int cumSum = ans[l][j];
			m[cumSum].pb(19 - j);
		}
		//debug(m);
		int soln = -1;
		//int current = stoi(v[l], nullptr, 2);
		vi keys;
		vi vals;
		for (auto i : m)
		{
			int cumSum = i.first;
			keys.pb(cumSum);
			if (cumSum == 0)
			{
				vals.pb(0);
				continue;
			}
			vi pos = i.second;
			int sum = 0;
			for (auto j : pos)
			{
				int val = (1 << j);
				sum = sum + val;
			}
			vals.pb(sum);

			// debug(cumSum);
			// debug(sum);
			// debug(soln);
		}
		debug(sz(keys));
		debug(keys);
		debug(vals);
		for (int i = sz(keys) - 1; i >= 0; i--)
		{
			if (i != sz(keys) - 1)
			{
				vals[i] = vals[i] + vals[i + 1];
			}
			if (vals[i] >= k)
			{
				soln = l + keys[i];
			}
		}

		cout << ((soln == -1) ? (-1) : (soln)) << " ";
	}
	cout << endl;

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