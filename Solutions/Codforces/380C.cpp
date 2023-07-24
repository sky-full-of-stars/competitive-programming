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

class node
{
public:
	int close, open, full;
public:
	node()
	{
		close = 0, open = 0, full = 0;
	}
	node(int _c, int _o, int _f)
	{
		close = _c;
		open = _o;
		full = _f;
	}
};

class segTree {
	vector<node> seg;

private:
	node merge(node l, node r)
	{
		int mergedFull = min(l.open, r.close);
		int newFull = l.full + r.full + mergedFull;
		int newOpen = l.open + r.open - mergedFull;
		int newClose = l.close + r.close - mergedFull;
		return node(newClose, newOpen, newFull);
	}
public:
	segTree(int n)
	{
		seg.resize(4 * n);
	}

	void build(int idx, int lo, int hi, string& s)
	{
		if (lo == hi)
		{
			seg[idx] = node((s[lo] == ')'), (s[lo] == '('), 0);
			return;
		}

		int mid = (lo + hi) >> 1;
		build(2 * idx + 1, lo, mid, s);
		build(2 * idx + 2, mid + 1, hi, s);
		seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
	}

	node query(int idx, int lo, int hi, int l, int r)
	{
		//no overlap
		// lo hi l r OR l r lo hi
		if (hi < l or r < lo)
		{
			return node();
		}

		//complete overlap
		// l low high r
		if ( lo >= l and r >= hi)
		{
			return seg[idx];
		}

		//partial overlap
		int mid = (lo + hi) / 2;
		node left = query(2 * idx + 1, lo, mid, l, r);
		node right = query(2 * idx + 2, mid + 1, hi, l, r);
		return merge(left , right);
	}
};

void solve()
{
	string s; cin >> s;
	int n = sz(s);

	segTree obj(n);
	obj.build(0, 0, n - 1, s);

	int t; cin >> t;
	while (t--)
	{
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << obj.query(0, 0, n - 1, l, r).full * 2 << endl;
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