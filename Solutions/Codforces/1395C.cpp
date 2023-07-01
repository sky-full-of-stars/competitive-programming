#include "bits/stdc++.h"
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

bool valid(int ans, vi&a, vi&b)
{
	for (int i = 0; i < sz(a); i++)
	{
		bool found = false;
		for (int j = 0; j < sz(b); j++)
		{
			//if ans has xth bit not set
			//then all we need is a pair whose xth bit is also not set

			//if ans has xth bit set
			//then, how do you know the ors of all c's will also have xth bit set?

			//observe that adding 1s anywhere unwanted, will only increase the ans
			//we can prove that our answer will have only required bits set.
			//we can also prove this by proof by contradiction

			//lets say our 'ans' has xth bit set
			//none of c's have xth bit set
			//then, we'll have a number 'realAns' which is less than 'ans' and doesnt have xth bit set.
			//since 'realAns' also satisifies our check and is less than 'ans' we'd have returned 'realAns' before even coming to check for 'ans'

			//if proof was not clear
			// think of example
			// ans = 11001
			// c1  = 01000
			// c2  = 10000
			//note that there's an extra set bit in 'ans'
			// we will have a lower number 'realAns' < 'ans' who doesnt have this unncessary bit set
			// realAns = 11000
			// realAns < ans
			// we'll return realAns not ans
			// so we can be sure that mininum value of all possible values of answer has only required bits set.
			if (((a[i]&b[j]) | ans) == ans)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			return false;
		}
	}
	return true;
}

void solve()
{
	int n, m; read(n, m);

	vi a(n); ipArr(a, n);
	vi b(m); ipArr(b, m);

	for (int i = 0; i < (1 << 9); i++)
	{
		if (valid(i, a, b))
		{
			cout << i << endl;
			return;
		}
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