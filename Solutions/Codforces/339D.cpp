// this is 2nd day and 2nd problem of segtree

// ref: https://www.youtube.com/watch?v=NEG-SoyigGE
//    : https://www.youtube.com/live/rXnXRU8yMF0?feature=share

// will continue seg tree for today and tom.
// plan is to just know it exists and use basic usecases.


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


class segTree {
public:
	int size;
	vi seg;

public:
	segTree(int _n)
	{
		int N = (1 << _n);
		size = N;
		seg.resize(4 * N);
	}

	void build(int idx, int lo, int hi, vi& v, bool isOr)
	{
		if (lo == hi)
		{
			seg[idx] = v[lo];
			return;
		}

		int mid = (lo + hi) >> 1;
		build(2 * idx + 1, lo, mid, v, !isOr);
		build(2 * idx + 2, mid + 1, hi, v, !isOr);
		if (isOr)
		{
			seg[idx] = (seg[2 * idx + 1] | seg[2 * idx + 2]);
		}
		else
		{
			seg[idx] = (seg[2 * idx + 1] ^ seg[2 * idx + 2]);
		}
	}

	void build(vi& v)
	{
		int n = log2(size);
		debug(n);
		if (n & 1)
		{
			return build(0, 0, size - 1, v, 1);
		}
		else
		{
			return build(0, 0, size - 1, v, 0);
		}
	}


	void update(int pos, int val, int idx, int lo, int hi, bool isOr)
	{
		if (lo == hi)
		{
			seg[idx] = val;
			return;
		}

		int mid = (lo + hi) >> 1;
		if (pos <= mid)
		{
			update(pos, val, 2 * idx + 1, lo, mid, !isOr);
		}
		else
		{
			update(pos, val, 2 * idx + 2, mid + 1, hi, !isOr);
		}
		if (isOr)
		{
			seg[idx] = (seg[2 * idx + 1] | seg[2 * idx + 2]);
		}
		else
		{
			seg[idx] = (seg[2 * idx + 1] ^ seg[2 * idx + 2]);
		}
	}

	void update(int pos, int val)
	{
		int n = log2(size);
		if (n & 1)
		{
			return update(pos, val, 0, 0, size - 1, 1);
		}
		else
		{
			return update(pos, val, 0, 0, size - 1, 0);
		}
	}
};

void solve()
{
	int n, q;
	cin >> n >> q;
	vi v(1 << n);
	ipArr(v, 1 << n);

	segTree obj(n);
	obj.build(v);
	debug(obj.seg[0]);
	while (q--)
	{
		int pos, val;
		cin >> pos >> val;
		pos--;
		obj.update(pos, val);
		cout << obj.seg[0] << endl;
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