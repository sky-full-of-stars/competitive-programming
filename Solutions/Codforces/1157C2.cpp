//hello friend, how have you been?
//did you miss me when I was gone?
//lots of things going on with me, I promise I'll tell you everything. Slowly, surely.

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
	vi v(n); ipArr(v, n);

	vector<char> ans;
	int l = 0, r = n - 1;

	bool done = false;
	int prev = -1;
	while (l <= r)
	{
		if (l == r and v[l] > prev)
		{
			ans.pb('L');
			done = true;
			break;
		}

		if (v[l] < v[r] and (ans.empty() or v[l] > prev))
		{
			prev = v[l];
			ans.pb('L');
			l++;
		}
		else if (v[r] < v[l] and (ans.empty() or v[r] > prev))
		{
			prev = v[r];
			ans.pb('R');
			r--;
		}
		else if (v[l] == v[r])
		{
			if (!ans.empty() and v[l] < prev)
			{
				//done
				done = true;
				break;
			}
			else
			{
				break;
			}
		}
		else if (!ans.empty() and v[l] > prev)
		{
			prev = v[l];
			ans.pb('L');
			l++;
		}
		else if (!ans.empty() and v[r] > prev)
		{
			prev = v[r];
			ans.pb('R');
			r--;
		}
		else
		{
			//done
			done = true;
			break;
		}
	}

	if (done)
	{
		cout << sz(ans) << endl;
		for (auto i : ans)
		{
			cout << i;
		}
		cout << endl;
		return;
	}

	vector<char> strtLeft;
	int templ = l;
	strtLeft.pb('L');
	templ++;
	while (templ <= r)
	{
		if (v[templ] > v[templ - 1])
		{
			strtLeft.pb('L');
			templ++;
		}
		else
		{
			break;
		}
	}
	//debug(strtLeft);

	vector<char> strtRight;
	int tempr = r;
	strtRight.pb('R');
	tempr--;
	while (tempr >= l)
	{
		if (v[tempr] > v[tempr + 1])
		{
			strtRight.pb('R');
			tempr--;
		}
		else
		{
			break;
		}
	}
	//debug(strtRight);

	if (sz(strtLeft) > sz(strtRight))
	{
		for (auto i : strtLeft)
		{
			ans.pb(i);
		}
	}
	else if (sz(strtRight) > sz(strtLeft))
	{
		for (auto i : strtRight)
		{
			ans.pb(i);
		}
	}
	else
	{
		for (auto i : strtRight)
		{
			ans.pb(i);
		}
	}

	cout << sz(ans) << endl;
	for (auto i : ans)
	{
		cout << i;
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
	int t = 1; //cin>>t;
	while (t--) solve();
	return 0;
}