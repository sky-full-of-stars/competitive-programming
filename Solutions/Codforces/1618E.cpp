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
/*
----------------------------------------------------------------
5  5   4  1  4  5
81 75 75 93 93 87

output makes sense,

05 10 15 20 25 30
30 05 10 15 20 25
20 24 04 08 12 16
04 05 06 01 02 03
12 16 20 24 04 08
10 15 20 25 30 05
sums up to [81 75 75 93 93 87]
---------------------------------------------------------------
n = 3
a = [1,2,3]

then,
123
624
693

b1 = 1*a1 + 3*a2 + 2*a3
b2 = 2*a1 + 1*a2 + 3*a3
b3 = 3*a1 + 2*a2 + 1*a3

can't find pattern for bi, lets proceed to n=5
----------------------------------------------------------------

n= 5
a = [1,2,3,4,5]

then,
01 02 03 04 05
10 02 04 06 08
12 15 03 06 09
12 16 20 04 08
10 15 20 25 05
b1.   b3

b1 = 1*a1 + 5*a2 +        4*a3 + 3*a4 + 2*a5
...
b3 = 3*a1 + 2*a2 +        1*a3 + 5*a4 + 4*a5
b4 = 4*a1 + 3*a2 + 2*a3 + 1*a4 + 5*a5
..
bi = i*a1 + (i-1)*a2.....(1)*ai+
                                 n*ai+1 + (n-1)* ai+2 ... (i+1)*(an)

----------------------------------------------------------------

b1+b2+...+bn = (n*(n+1)/2)*(a1) + (n*(n+1)/2)*(a2)+ .....(n*(n+1)/2)*(an)
b1+b2+...+bn = (n*(n+1)/2)*(a1+a2+...+an)
a1+a2+...+an = (b1+b2+...+bn) / (n/2 *(n+1))

ie, sigmaB is multiple of sigmaN
&   sigmaA = sigmaB/sigmaN
----------------------------------------------------------------

b3 = 3*a1 + 2*a2 + 1*a3 + 5*a4 + 4*a5
b4 = 4*a1 + 3*a2 + 2*a3 + 1*a4 + 5*a5

b4 - b3 = (a1 + a2 + a3  -4 a4 + a5)
        = (a1 + a2 + a3  +a4 + a5) - 5 a4
b4 - b3 = sigmaA - n(a4)
bCur - bPrev = sigmaA - n(Acur)
delta = sigmaA - n(Acur)

(Acur) = (sigmaA - delta) / n
----------------------------------------------------------------
*/
void solve()
{
	int n; cin >> n;
	vi v(n); ipArr(v, n);

	int sigmaB = accumulate(all(v), 0ll);
	int sigmaN = n * (n + 1) / 2;

	if (sigmaB % sigmaN)
	{
		no; return;
	}
	else
	{
		int sigmaA = (sigmaB / sigmaN);
		vi ans;
		for (int cur = 0; cur < n; cur++)
		{
			int prev = (cur == 0) ? n - 1 : cur - 1;
			int delta = v[cur] - v[prev];

			int dif = sigmaA - delta;
			if (dif <= 0 or dif % n)
			{
				no; return;
			}
			else
			{
				ans.pb(dif / n);
			}
		}
		yes;
		opArr(ans, n);
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