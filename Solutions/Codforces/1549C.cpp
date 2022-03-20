//we start again today with a new hope.
//courage to start over and not give up is what makes is really alive.

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
int max(int a, int b) { return a >= b ? a : b;}
//---------------------------------------------------------------------------------------------------------//


const int maxN = 2e5 + 7;

si gp[maxN];

bool isLastStanding(int i)
{
	if (!sz(gp[i]))
	{
		return true;
	}
	int friendWithMaxPower = *(gp[i].rbegin());
	if (friendWithMaxPower < i)
	{
		return true;
	}
	return false;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		gp[u].insert(v);
		gp[v].insert(u);
	}

	set<int> lastStanding;
	for (int i = 1; i <= n; i++)
	{
		if (isLastStanding(i))
			lastStanding.insert(i);
	}

	int q; cin >> q;
	while (q--)
	{
		int type; cin >> type;
		if (type == 3)
		{
			cout << max(sz(lastStanding), 1) << endl; // claim: atleast one man always remains
		}
		else
		{
			int u, v; cin >> u >> v;
			if (type == 1)
			{
				gp[u].insert(v);
				gp[v].insert(u);

				if (isLastStanding(u))
					lastStanding.insert(u);
				else
					lastStanding.erase(u);

				if (isLastStanding(v))
					lastStanding.insert(v);
				else
					lastStanding.erase(v);

				// //already present, then check if it's still valid after new friend is added.
				// if (present(lastStanding, u) and v > u)
				// {
				// 	lastStanding.erase(u);
				// }
				// else //else, it becomes candidate only if its newly added node and it satisifies condition
				// {
				// 	if (sz(gp[u]) == 1 and v < u)
				// 	{
				// 		lastStanding.insert(u);
				// 	}
				// }


				// if (present(lastStanding, v) and u > v)
				// {
				// 	lastStanding.erase(v);
				// }
				// else
				// {
				// 	if (sz(gp[v]) == 1 and u < v)
				// 	{
				// 		lastStanding.insert(v);
				// 	}
				// }
			}
			else
			{
				gp[u].erase(v);
				gp[v].erase(u);

				if (isLastStanding(u))
					lastStanding.insert(u);
				else
					lastStanding.erase(u);

				if (isLastStanding(v))
					lastStanding.insert(v);
				else
					lastStanding.erase(v);
				// if (present(lastStanding, u) and sz(gp[u]) == 0) //remove from candidate if it's v was only u's friend before
				// {
				// 	lastStanding.erase(u);
				// }
				// if (present(lastStanding, v) and sz(gp[v]) == 0)
				// {
				// 	lastStanding.erase(v);
				// }
			}
		}
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