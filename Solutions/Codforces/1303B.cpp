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
int max(int a, int b) { return a >= b ? a : b;}
int min(int a, int b) { return a <= b ? a : b;}
int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
bool isPowOfTwo(int x) {return (x && (!(x & (x - 1))));}
//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;

void solve()
{
	int n, g, b;
	cin >> n >> g >> b;

	int reqdG = (n + 1) / 2;
	int fullCyclesNeed = reqdG / g;
	int moves = fullCyclesNeed * (g + b);
	if (reqdG % g == 0)
	{
		moves -= b;
	}
	else
	{
		moves += (reqdG % g);
	}
	cout << max(n, moves) << endl;

	/*
	if (g >= n)
	{
		cout << n << endl;
		return;
	}

	int reqdG = (n + 1) / 2;
	int reqdB = n - reqdG;
	if (g >= reqdG and b >= reqdB)
	{
		cout << n << endl;
		return;
	}

	int goodCyclesNeeded = reqdG / g;
	int extraGoodNeeded = reqdG % min(g, reqdG);

	int badCyclesNeeded = reqdB / b;
	int extraBadNeeded = reqdB % min(b, reqdB);

	int fullCyclesNeeded;

	//debug(goodCyclesNeeded, badCyclesNeeded);
	//debug(extraGoodNeeded, extraBadNeeded);

	int count = 0;
	if (badCyclesNeeded > goodCyclesNeeded)
	{
		fullCyclesNeeded = badCyclesNeeded;
		count = fullCyclesNeeded * (g + b);

		if (extraBadNeeded)
		{
			count += g;
			count += extraBadNeeded;
		}
		cout << count;
	}
	else
	{
		fullCyclesNeeded = max(goodCyclesNeeded - 1, badCyclesNeeded);
		//debug(fullCyclesNeeded);
		goodCyclesNeeded -= fullCyclesNeeded;
		//debug(goodCyclesNeeded);
		count = fullCyclesNeeded * (g + b);
		//debug(count);
		count += goodCyclesNeeded * g;
		if (extraGoodNeeded)
		{
			count += b;
			count += extraGoodNeeded;
		}
		if (extraBadNeeded)
		{
			count += g;
			count += extraBadNeeded;
		}
		cout << count << endl;
	}
	*/

	/*
	int reqdG = (n + 1) / 2;
	int reqdB = n - reqdG;

	int ans = 0;
	//debug(reqdG, reqdB);

	while (true)
	{
		int needToUSe = min(g, reqdG);
		reqdG -= needToUSe;
		ans += needToUSe;
		//dbg(ans, reqdG, reqdB);

		int remGood = g - needToUSe;
		if (remGood > 0 and reqdB > 0)
		{
			needToUSe = min(reqdB, remGood);
			reqdB -= needToUSe;
			ans += needToUSe;
		}

		if (reqdG == 0 and reqdB == 0)
		{
			cout << ans << endl;
			return;
		}

		if (reqdG != 0)
		{
			ans += b; //add all days so that I can goto good days again
			reqdB = max(0, reqdB - b);
			//dbg(ans, reqdG, reqdB);
		}
		else
		{
			needToUSe = min(b, reqdB);
			reqdB -= needToUSe;
			ans += needToUSe;
			//dbg(ans, reqdG, reqdB);
		}

		if (reqdG == 0 and reqdB == 0)
		{
			cout << ans << endl;
			return;
		}
	}

	cout << ans << endl;
	*/

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