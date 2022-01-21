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
#define all(i) (i.begin(),i.end())

//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;

void solve()
{
	int n, m; read(n, m);
	int a[n][m];

	bool allZero = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j])
			{
				allZero = false;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j])
			{
				bool iscolone = true;
				bool isrowone = true;
				for (int k = 0; k < n; k++) //col
				{
					if (!a[k][j])
					{
						iscolone = false; break;
					}
				}
				for (int k = 0; k < m; k++)
				{
					if (!a[i][k])
					{
						isrowone = false; break;
					}
				}
				if (isrowone == false and iscolone == false)
				{
					cout << "NO" << endl;
					return;
				}
			}
		}
	}

	vi rowsWithones;
	for (int i = 0; i < n; i++)
	{
		bool flg = true;
		for (int j = 0; j < m; j++)
		{
			if (!a[i][j])
			{
				flg = false; break;
			}
		}
		if (flg)
			rowsWithones.pb(i);
	}

	vi colWithones;
	for (int i = 0; i < m; i++)
	{
		bool flg = true;
		for (int j = 0; j < n; j++)
		{
			if (!a[j][i])
			{
				flg = false; break;
			}
		}
		if (flg)
			colWithones.pb(i);
	}

	int ans[n][m];
	memset(ans, 0, sizeof(ans));

	int count = 0;
	for (int i : colWithones)
	{
		for (int j : rowsWithones)
		{
			ans[j][i] = 1;
			count++;
		}
	}

	if (!count and !allZero)
	{
		cout << "NO" << endl;
		return;
	}
	else
	{
		cout << "YES" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
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
