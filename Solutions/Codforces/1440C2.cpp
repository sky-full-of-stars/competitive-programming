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
#define opArr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()

int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
bool isPowOfTwo(int x) {return (x && (!(x & (x - 1))));}
//---------------------------------------------------------------------------------------------------------//

const int maxN = 1e2 + 7;
int a[maxN][maxN];

//flips bits
void flip(pi p, pi q, pi r)
{
	a[p.ff][p.ss] = a[p.ff][p.ss] ^ 1;
	a[q.ff][q.ss] = a[q.ff][q.ss] ^ 1;
	a[r.ff][r.ss] = a[r.ff][r.ss] ^ 1;
}
void flip(pi p)
{
	a[p.ff][p.ss] = a[p.ff][p.ss] ^ 1;
}


// make 'a' and b' and 'c' as '0'
vi process(pi a, pi b, pi c)
{
	vi ans = {a.ff, a.ss, b.ff, b.ss, c.ff, c.ss};
	flip(a, b, c);
	return ans;
}

// make 'a' as '0' : use 'b' and 'c' and 'd' as adjacent blocks
vector<vi> makeBlockZero(pi a, pi b, pi c, pi d)
{
	vector<vi> ans;
	vi f = {a.ff, a.ss, b.ff, b.ss, c.ff, c.ss};
	vi s = {a.ff, a.ss, b.ff, b.ss, d.ff, d.ss};
	vi t = {a.ff, a.ss, d.ff, d.ss, c.ff, c.ss};
	ans.pb(f);
	ans.pb(s);
	ans.pb(t);
	flip(a);
	return ans;
}

// a,b,c,d pairs contain 1's and 0's in order now.
void reArrangePairs(pi &ap, pi &b, pi &c, pi &d)
{
	// make 'a' contain '1' if anything is 1.
	if (a[b.ff][b.ss])
	{
		swap(ap, b);
	}
	else if (a[c.ff][c.ss])
	{
		swap(ap, c);
	}
	else if (a[d.ff][d.ss])
	{
		swap(ap, d);
	}

	// make 'b' contain '1' if anything is 1.
	if (a[c.ff][c.ss])
	{
		swap(b, c);
	}
	else if (a[d.ff][d.ss])
	{
		swap(b, d);
	}

	// make 'c' contain '1' if anything is 1.
	if (a[d.ff][d.ss])
	{
		swap(c, d);
	}
}

void show(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cerr << a[i][j] << " ";
		}
		cerr << endl;
	}
	cerr << endl;
}
void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c; cin >> c;
			a[i][j] = c - '0';
		}
	}

	vector<vi> ans;

	//all except last 2 rows, last 2 cols
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = 1; j <= m - 2 ; j++)
		{
			if (a[i][j])
			{
				pi a, b, c, d;
				a = {i, j};
				b = {i + 1, j };
				c = {i + 1, j + 1};
				ans.pb(process(a, b, c));
			}
		}
	}

	//last 2 rows (except last 2 cols)
	for (int j = 1; j <= m - 2; j++)
	{
		for (int i = n - 1; i <= n; i++)
		{
			if (a[i][j])
			{
				pi a, b, c, d;
				if (i == n - 1)
				{
					a = {i, j};
					b = {i , j + 1};
					c = {i + 1, j + 1};
				}
				else
				{
					a = {i, j};
					b = {i - 1, j + 1};
					c = {i, j + 1};
				}
				ans.pb(process(a, b, c));
			}
		}
	}
	//last 2 cols (except last 2 rows)
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = m - 1; j <= m; j++)
		{
			if (a[i][j])
			{
				pi a, b, c, d;
				if (j == m - 1)
				{
					a = {i, j};
					b = {i + 1, j };
					c = {i + 1, j + 1};
				}
				else
				{
					a = {i, j};
					b = {i + 1, j - 1};
					c = {i + 1, j};
				}
				ans.pb(process(a, b, c));
			}
		}
	}

	//last 2*2 block.
	pi ap, bp, cp, dp;
	ap = {n - 1, m - 1};
	bp = {n - 1, m};
	cp = {n, m - 1};
	dp = {n, m};

	reArrangePairs(ap, bp, cp, dp);
	//debug(ap, bp, cp, dp);
	int cnt = 0;
	for (int i = n - 1; i <= n; i++)
	{
		for (int j = m - 1; j <= m; j++)
		{
			if (a[i][j])
			{
				cnt++;
			}
		}
	}
	//debug(cnt);
	vector<vi> extra3OpFor1Block;
	if (cnt == 4)
	{
		ans.pb(process(ap, bp, cp)); // a,b,c became 0.
		extra3OpFor1Block = makeBlockZero(dp, ap, bp, cp); // d became 0.
	}
	else if (cnt == 3)
	{
		ans.pb(process(ap, bp, cp)); // all 3 became 0
	}
	else if (cnt == 2)
	{
		ans.pb(process(ap, bp, cp)); // a,b done. c became 1.
		extra3OpFor1Block = makeBlockZero(cp, ap, bp, dp); // c done.
	}
	else if (cnt == 1)
	{
		extra3OpFor1Block = makeBlockZero(ap, cp, bp, dp); // a became 0.
	}
	else if (cnt == 0)
	{
		;
	}
	for (auto &i : extra3OpFor1Block)
		ans.pb(i);

	show(n, m);
	cout << sz(ans) << endl;
	for (auto i : ans)
	{
		vi eachLine = i;
		opArr(eachLine, 6);
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