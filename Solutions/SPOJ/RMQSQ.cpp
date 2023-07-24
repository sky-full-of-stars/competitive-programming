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


class segTree {
public:
	int n;
	vi seg;

public:
	segTree(int _n)
	{
		n = _n;
		seg.resize(4 * _n);
	}

	void build(int idx, int lo, int hi, vi& v)
	{
		if (lo == hi)
		{
			seg[idx] = v[lo];
			return;
		}

		int mid = (lo + hi) >> 1;
		build(2 * idx + 1, lo, mid, v);
		build(2 * idx + 2, mid + 1, hi, v);
		seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
	}

	void build(vi v)
	{
		return build(0, 0, n - 1, v);
	}

	int query(int l, int r, int idx , int lo, int hi)
	{
		//no overlap
		//lo hi l r OR l r lo hi
		if (hi < l or r < lo)
		{
			return INT_MAX;
		}

		//complete overlap
		// l lo hi r
		if (l <= lo and r >= hi)
		{
			return seg[idx];
		}

		//partial overlap
		int mid = (lo + hi) >> 1;
		int left = query(l, r, 2 * idx + 1, lo, mid);
		int right = query(l, r, 2 * idx + 2, mid + 1, hi);
		return min(left , right);
	}

	int query(int l, int r)
	{
		if (l <= r)
			return query(l, r, 0, 0, n - 1);
		else
			return -1;
	}

	void update(int pos, int val, int idx, int lo, int hi)
	{
		if (lo == hi)
		{
			seg[idx] = val;
			return;
		}

		int mid = (lo + hi) >> 1;
		if (pos <= mid)
		{
			update(pos, val, 2 * idx + 1, lo, mid);
		}
		else
		{
			update(pos, val, 2 * idx + 2, mid + 1, hi);
		}
		seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
	}

	void update(int pos, int val)
	{
		return update(pos, val, 0, 0, n - 1);
	}

};


void solve()
{
	int n; cin >> n;
	vi v(n); ipArr(v, n);

	segTree obj(n);
	obj.build(v);

	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << obj.query(l, r) << endl;
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
	int t = 1; //cin>>t;
	while (t--) solve();
	return 0;
}