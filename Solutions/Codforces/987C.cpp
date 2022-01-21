#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include <bits/headerfile.hpp>
#else
#define dbg (...)
#endif

//---------------------------------------------------------------------------------------------------------//
using namespace std;

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
#define INF 1e9
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


const int maxN = 3e3 + 3;
int n;
vi siz(maxN);
vi cost(maxN);

int memo[maxN][4][maxN]; // memory limit exceeded. refer 987_C.cpp for 1d impl.


int getAns(int start, int count, int prevSelectedIdx)
{

	if (count == 0) {
		return  0;
	}

	if (start == n) {
		return  1e9;
	}

	if (memo[start][count][prevSelectedIdx] != -1)
		return memo[start][count][prevSelectedIdx];

	int ans = 1e9;

	// select cur idx
	int include = INF;
	if (start<n and count>0 and siz[start] > siz[prevSelectedIdx]) {
		include = cost[start];

		int nextRecursiveCall = getAns(start + 1, count - 1, start);
		//little hack for overflow. not sure if it works.
		if (nextRecursiveCall == INF) {
			include = INF;
		} else {
			include += nextRecursiveCall;
		}
	}


	// dont select cur idx
	int exclude = INF;
	if (start < n) {
		exclude = getAns(start + 1, count, start);
	}

	ans = min(include, exclude);

	debug(start, count, prevSelectedIdx, ans);
	return memo[start][count][prevSelectedIdx] = ans;
}



void solve()
{
	cin >> n;
	ipArr(siz, n);
	ipArr(cost, n);
	siz[-1] = -1;
	memset(memo, -1, sizeof(memo));
	int ans = getAns(0, 3 , -1);
	if (ans < 0 or ans >= 1e9) //INF or overflow by any chance
		cout << -1 << endl;
	else
		cout << ans;
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
