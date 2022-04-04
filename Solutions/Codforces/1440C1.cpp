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
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()

int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
bool isPowOfTwo(int x) {return (x && (!(x & (x - 1))));}
//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e2 + 7;
int a[maxN][maxN];

void opArr(vi v, int n)
{
	for (int i = 0; i < (n / 2); i++)
	{
		cout << v[i] << " " << v[i + 3] << " ";
	}
	cout << endl;
}

void process(int i, int j)
{
	vi f = {i, i, i + 1, j, j + 1, j};
	vi s = {i, i, i + 1, j, j + 1, j + 1};
	vi t = {i, i + 1, i + 1, j, j, j + 1};
	opArr(f, 6);
	opArr(s, 6);
	opArr(t, 6);
}

void processLastRow(int i, int j)
{
	vi f = {i, i - 1, i - 1, j, j, j + 1};
	vi s = {i, i - 1, i, j, j, j + 1};
	vi t = {i, i - 1, i, j, j + 1, j + 1};
	opArr(f, 6);
	opArr(s, 6);
	opArr(t, 6);
}

void processLastCol(int i, int j)
{
	pi a, b, c, d;
	a = {i, j};
	b = {i, j - 1};
	c = {i + 1, j - 1};
	d = {i + 1, j};
	vi f = {a.ff, b.ff, c.ff, a.ss, b.ss, c.ss};
	vi s = {a.ff, b.ff, d.ff, a.ss, b.ss, d.ss};
	vi t = {a.ff, c.ff, d.ff, a.ss, c.ss, d.ss};
	opArr(f, 6);
	opArr(s, 6);
	opArr(t, 6);
}

void processLastEle(int i, int j)
{
	pi a, b, c, d;
	a = {i, j};
	b = {i, j - 1};
	c = {i - 1, j };
	d = {i - 1, j - 1};
	vi f = {a.ff, b.ff, c.ff, a.ss, b.ss, c.ss};
	vi s = {a.ff, b.ff, d.ff, a.ss, b.ss, d.ss};
	vi t = {a.ff, c.ff, d.ff, a.ss, c.ss, d.ss};
	opArr(f, 6);
	opArr(s, 6);
	opArr(t, 6);
}
void solve()
{
	int n, m; cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c; cin >> c;
			if (c == '1')
				ans++;
			a[i][j] = c - '0';
		}
	}

	cout << ans * 3 << endl;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m ; j++)
		{
			if (a[i][j])
				process(i, j);
		}
	}

	//last row
	for (int j = 1; j < m; j++)
	{
		if (a[n][j])
			processLastRow(n, j);
	}

	//last col
	for (int j = 1; j < n ; j++)
	{
		if (a[j][m])
			processLastCol(j, m);
	}

	if (a[n][m])
	{
		processLastEle(n, m);
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
	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}