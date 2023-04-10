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

const int N = 2e5 + 2;
int f[N];
int invF[N];

int fpow(int n, int m)
{
	int ans = 1;
	while (m)
	{
		if (m & 1)
		{
			ans = (ans * n) % mod;
			m--;
		}
		else
		{
			n = (n * n) % mod;
			m /= 2;
		}
	}
	return ans % mod;
}

void setUpFactorials()
{
	f[0] = invF[0] = 1;
	for (int i = 1; i < N; i++)
	{
		f[i] = (f[i - 1] * i) % mod;
		invF[i] = fpow(f[i], mod - 2);
	}
}



int permutation(int n, int r)
{
	if (r > n)
	{
		return 0;
	}
	return f[n] * invF[r] % mod * invF[n - r] % mod;
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	vi v(n);
	for (int &ele : v)
	{
		cin >> ele;
	}
	sortv(v);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int l = i + 1;
		int h = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
		int possibleWays = permutation(h - l, m - 1);
		//cerr << h - l << " " << m - 1 << " " << possibleWays << endl;
		ans = (ans + possibleWays) % mod;
	}

	cout << ans << endl;
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
	setUpFactorials();
	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}