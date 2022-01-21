#include "bits/stdc++.h"

using namespace std;

#define int long long // −9·10^18 to 9·10^18
#define lll __int128_t //−10^38 to 10^38
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mi;

//const
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;

// inputs & output & debug
#define w(t) int t; cin>> t; while(t--)

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << " "), ...);
}

#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

//useful functions
//#define deb(x) cout<<#x<<": "<<x<<endl;
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define gcd(x,y) return __gcd(x,y);
#define sz(a) int((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(ll i=0;i<n;i++) cin>>a[i];
#define print_arr(arr,n) for(ll i=0;i<n;i++) cout<<arr[i]<<"\n"[i=n];
#define sortv(a) sort(a.begin(),a.end())


void fio()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Desktop/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Desktop/CP/output.txt", "w", stdout);
#endif
}


vi gp[100007];
int vis[100007];
void dfs(int s)
{
	vis[s] = 1;
	for (int child : gp[s])
		if (!vis[child])
			dfs(child);
}

void solve()
{

	int n; cin >> n;
	int _m = 0;
	w(m)
	{
		int a, b;
		_m++;
		cin >> a >> b;
		gp[a].pb(b); gp[b].pb(a);
	}

	deb(_m);

	dfs(1);

	bool tree = (_m == n - 1);
	if (!tree)
	{
		cout << "NO" << endl; return;
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			tree = false;

	if (tree)
	{
		cout << "YES" << endl; return;
	}
	else {
		cout << "NO" << endl; return;
	}











}

int32_t main()
{
	fio();
	return solve(), 0;
}
