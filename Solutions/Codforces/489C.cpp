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
int min(int a, int b) { return (a <= b) ? a : b ;}
int max(int a, int b) { return (a >= b) ? a : b ;}

//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;

vi g;
bool gPossible = true;
void getGreatest(int len, int sum)
{
	if (len == 0 and sum == 0)
	{
		return;
	}
	if (len == 0 and sum != 0)
	{
		gPossible = false;
		return;
	}

	int ele = min(9, sum);
	g.pb(ele);
	getGreatest(len - 1, max(sum - ele, 0));
}

vi s;
bool sPossible = true;
bool fillLast = false;
void getSmallest(int len, int sum)
{
	//debug(len, sum);
	if (len == 0 and sum == 0)
	{
		return;
	}
	if (len == 0 and sum != 0)
	{
		sPossible = false;
		return;
	}
	int ele;
	if ((fillLast == 1 or sum == 1) and len == 1)
	{
		ele = 1;
	}
	else if ((fillLast == 1 or sum == 1) and len != 1)
	{
		ele = 0;
	}
	else
	{
		ele = min(9, sum);
		if ((sum - ele == 0) and (len != 1))
		{
			ele -= 1;
			fillLast = 1;
		}
	}
	s.pb(ele);
	//debug(ele);
	getSmallest(len - 1, max(sum - ele, 0));
}

void solve()
{
	int len, sum;
	cin >> len >> sum;

	if (sum == 0)
	{
		if (len > 1)
			cout << -1 << " " << -1 << endl;
		if (len == 1)
			cout << 0 << " " << 0 << endl;
		return;
	}

	if (sum <= len)
	{

		//print smallest
		g.clear();
		getGreatest(sum - 1 , sum - 1);
		cout << "1";
		for (int i = 0; i < len - sum; i++) cout << "0";
		for (int i = sz(g) - 1 ; i >= 0; i--) cout << g[i];
		cout << " ";

		//print largest
		g.clear();
		getGreatest(sum , sum );
		for (int i = 0 ; i < sz(g); i++) cout << g[i];
		for (int i = 0; i < len - sum; i++)cout << "0";
		cout << " ";

		return;

	}

	getSmallest(len, sum);
	if (sPossible)
	{
		reverse(all(s));
		for (int i : s) cout << i;
		cout << " ";
	}
	else
	{
		cout << "-1" << " ";
	}

	getGreatest(len, sum);
	if (gPossible)
	{
		for (int i : g) cout << i;
		cout << " ";
	}
	else
	{
		cout << "-1" << " ";
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
