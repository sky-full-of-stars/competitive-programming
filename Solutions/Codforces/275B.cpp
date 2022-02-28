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
int row[52][52];
int col[52][52];

bool rowFirstColNext(int x1, int y1, int x2, int y2)
{

	int colDist = abs(y1 - y2) + 1;
	int val = row[x1][max(y1, y2)] - row[x1][min(y1, y2) - 1];

	if (val != colDist)
		return false;

	int rowDist = abs(x1 - x2) + 1;
	val = col[max(x1, x2)][y2] - col[min(x1, x2) - 1][y2];
	if (val != rowDist)
		return false;

	return true;
}

bool colFirstRowNext(int x1, int y1, int x2, int y2)
{
	int rowDist = abs(x2 - x1) + 1;
	int val = col[max(x2, x1)][y1] - col[min(x2, x1) - 1][y1];
	if (val != rowDist )
		return false;

	int colDist = abs(y2 - y1) + 1;
	val = row[x2][max(y1, y2)] - row[x2][min(y1, y2) - 1];
	if (val != colDist)
		return false;

	return true;
}

void solve()
{
	int n, m; cin >> n >> m;
	int mat[n + 1][m + 1];

	vpi v;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			if (ch == 'W')
				mat[i][j] = 0;
			else
			{
				mat[i][j] = 1;
				v.push_back({i, j});
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			row[i][j] = col[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mat[i][j])
			{
				row[i][j] = row[i][j - 1] + 1;
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (mat[j][i])
			{
				col[j][i] = col[j - 1][i] + 1;
			}
		}
	}

	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= m; j++)
	// 	{
	// 		cerr << row[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }
	// cerr << endl;
	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= m; j++)
	// 	{
	// 		cerr << col[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }
	// cerr << endl;


	int l = sz(v);
	for (int i = 0; i < l; i++)
	{
		for (int j = i + 1; j < l; j++)
		{
			int x1 = v[i].ff;
			int y1 = v[i].ss;
			int x2 = v[j].ff;
			int y2 = v[j].ss;

			if (rowFirstColNext(x1, y1, x2, y2) or colFirstRowNext(x1, y1, x2, y2))
			{
				continue;
			}
			else
			{
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;
	return;

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