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



vi possible{11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
int found = false;
//dfs to cache values. but nos in range of 1e9. -> MLE
bool isPossible(int n, map<int, char> &memo)
{
	if (binary_search(all(possible), n)) {
		found = true;
		memo[n] = 'Y';
		return true;
	}
	for (int i : possible) {
		if (n >= i and n % i == 0) {
			memo[n] = 'Y';
			return true;
		}
	}

	if (n <= 10) {
		memo[n] = 'F';
		found = false;
		return false;
	}

	if (memo[n] == 'Y' or memo[n] == 'N') {
		return memo[n];
	}

	for (int i : possible)
	{
		if (i <= n)
		{
			memo[n - i] = isPossible(n - i, memo) ? 'Y' : 'N';
			if (memo[n - i] == 'Y') {
				found = true;
				return found;
			}
		}
	}

	memo[n] = 'F';
	return found;
}

//bfs calls cant be cached. no not useful
map<int, bool> vis;
bool bfs(int n)
{
	queue<int> q;
	q.push(n);
	vis[n] = true;

	while (!q.empty())
	{
		int top = q.front();
		q.pop();

		if (top <= 10)
		{
			continue;
		}

		for (int i : possible)
		{
			if (!vis[top - i] and i < top )
			{
				vis[n - i] = true;
				q.push(top - i);
			}
			else if (i == top)
			{
				return true;
			}
		}
	}
	return false;
}
map<int, char> ok;
bool isOK(int n)
{
	if (ok[n] == 'T') {
		return true;
	}
	if (ok[n] == 'F') {
		return false;
	}
	for (int i = 0; i * 11 <= n; i++)
	{
		for (int j = 0; j * 111 <= n; j++)
		{
			if (11 * i + 111 * j == n)
			{
				ok[n] = 'Y';
				return true;
			}
		}
	}
	ok[n] = 'F';
	return false;
}
void solve()
{
	int n; cin >> n;
	found = false;
	map<int, char> memo;

	if (n < 11) {
		cout << "NO" << endl;
		return;
	}
	//https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem
	if (n > 1099) {
		cout << "YES" << endl;
		return;
	}
	if (isOK(n)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
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
