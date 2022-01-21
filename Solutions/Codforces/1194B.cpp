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
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ipArr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define opArr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()

//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;

void solve()
{
	int n, m; read(n, m);
	int a[n][m];

	//ip
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c; cin >> c;
			if (c == '.')
				a[i][j] = 0;
			else
				a[i][j] = 1;
			//cerr << a[i][j] << " ";
		}
		//cerr << endl;
	}

	//how many minutes each row takes
	vi minNeedRow(n);
	int minRowTime = INF;
	for (int i = 0; i < n; i++)
	{
		int c = 0;
		for (int j = 0; j < m; j++)
		{
			if (!a[i][j])
			{
				c++;
			}
		}
		minNeedRow[i] = c;
		minRowTime = min(minRowTime, c);
	}

	//how many minutes each col takes
	vi minNeedCol(m);
	int minColTime = INF;
	for (int i = 0; i < m; i++)
	{
		int c = 0;
		for (int j = 0; j < n; j++)
		{
			if (!a[j][i])
			{
				c++;
			}
		}
		minNeedCol[i] = c;
		minColTime = min(minColTime, c);
	}

	//debug(minNeedRow, minNeedCol);
	//debug(minColTime, minRowTime);

	vi eligibleRows, eligibleCols;
	for (int i = 0; i < n; i++)
	{
		if (minNeedRow[i] == minRowTime)
			eligibleRows.pb(i);
	}
	for (int i = 0; i < m; i++)
	{
		if (minNeedCol[i] == minColTime)
			eligibleCols.pb(i);
	}

	//debug(eligibleCols, eligibleRows);
	if (sz(eligibleCols) == 0 and sz(eligibleRows) == 0)
	{
		cout << 0 << endl;
		return;
	}

	int ans = INF;
	for (int i : eligibleRows)
	{
		for (int j : eligibleCols)
		{
			int timeNeeded = minNeedRow[i] + minNeedCol[j] - (a[i][j] == 0);
			//debug(i, j, timeNeeded);
			ans = min( ans, timeNeeded);
		}
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
	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}
