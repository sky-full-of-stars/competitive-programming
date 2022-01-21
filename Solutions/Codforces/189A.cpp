#include "bits/stdc++.h"

using namespace std;

#define int long long
#define cont continue;
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define mp make_pair
#define endl '\n'


typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

//const
#define EPS -999999999
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
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define op_arr(arr,n) for(int i=0;i<n;i++) cerr<<arr[i]<<" "; cerr<<endl;
#define fill_arr(arr,n,ele) for(int i=0;i<n;i++) arr[i]=ele;
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())

void fio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#else
#define cerr if(0) cerr
#endif
}

const int gp_size = (int)1e6 + 7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

int min(int a, int b)
{
	return a <= b ? a : b;
}
int max(int a, int b)
{
	return a <= b ? b : a;
}
void solve()
{

	int n, a, b, c; read(n, a, b, c);

	vi arr(3); arr[0] = a; arr[1] = b; arr[2] = c;
	sortv(arr);
	int mn, p, q;
	mn = arr[0];
	p = arr[1];
	q = arr[2];

	mi dp;
	for (int i = -q; i <= n; i++)
	{
		dp[i] = -1;
	}

	dp[mn] = 1;
	dp[p] = max(dp[p], 1);
	dp[q] = max(dp[q], 1);

	//op_arr(dp, n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (i < mn)
			cont;
		int temp = max(dp[i - a], max(dp[i - b], dp[i - c]));
		int total = (temp == -1) ? -1 : temp + 1;
		dp[i] = max(dp[i], total);
	}
	//op_arr(dp, n + 1);
	cout << dp[n] << endl;

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
