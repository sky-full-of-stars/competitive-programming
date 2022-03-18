// it was nice while it lasted. right?
//https://www.youtube.com/watch?v=hN24urQktVE

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

//https://www.youtube.com/watch?v=il5EJJhU-2o
void solve()
{
	int n; cin >> n;
	string s; cin >> s;
	int sheeps = 0;
	for (char i : s)
	{
		sheeps += (i == '*') ? 1 : 0;
	}
	if (!sheeps or sheeps == 1 or sheeps == n)
	{
		cout << 0 << endl;
		return;
	}

	vi pre(n + 1), suf(n + 1);
	pre[0] = suf[n] = 0;
	//pref[i] is num of moves to make all sheeps till i alligned at straight line ending at i.

	int sheepsSoFar = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			if (s[i - 1] == '*')
			{
				pre[i] = 0;
				sheepsSoFar = 1;
			}
			else
			{
				pre[i] = 0;
			}
			continue;
		}
		if (s[i - 1] == '*')
		{
			pre[i] = pre[i - 1];
			sheepsSoFar++;
		}
		else
		{
			pre[i] = pre[i - 1] + sheepsSoFar;
		}
	}

	int sheepsAhead = 0;
	for (int i = n ; i > 0; i--)
	{
		if (i == n)
		{
			if (s[i - 1] == '*')
			{
				suf[i] = 0;
				sheepsAhead = 1;
			}
			else
			{
				suf[i] = 0;
			}
			continue;
		}
		if (s[i - 1] == '*')
		{
			suf[i] = suf[i + 1];
			sheepsAhead++;
		}
		else
		{
			suf[i] = suf[i + 1] + sheepsAhead;
		}
	}

	//debug(pre, suf);

	//idea now is to keep ith sheep static and move rest of the sheeps to allign with ith
	int ans = INF;

	for (int i = 1; i <= n; i++)
	{
		if (s[i - 1] == '*')
		{
			int movesNeededToBringAllSheepsInLeft = pre[i - 1];
			int movesNeededToBringAllSheepsInRight = suf[i + 1];
			int totalMoves = movesNeededToBringAllSheepsInLeft + movesNeededToBringAllSheepsInRight;
			ans = min(ans, totalMoves);
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