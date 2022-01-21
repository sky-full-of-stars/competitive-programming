#include "bits/stdc++.h"

using namespace std;

#define int long long int
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
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

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
#define op_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
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

const int maxN = (int)1e5 + 7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

int n;
int a[maxN], b[maxN], c[maxN];
int dp[maxN][4];

int calc(int day, int prev)
{
	if (day == n)
		return 0;

	if (dp[day][prev] != -1)
		return dp[day][prev];

	int ans = INT_MIN;

	if (prev == 0) //a
	{
		int c1 = calc(day + 1, 1) + b[day];
		int c2 = calc(day + 1, 2) + c[day];
		ans = max(c1, c2);
	}
	else if (prev == 1) //b
	{
		int c1 = calc(day + 1, 0) + a[day];
		int c2 = calc(day + 1, 2) + c[day];
		ans = max(c1, c2);
	}
	if (prev == 2) //c
	{
		int c1 = calc(day + 1, 1) + b[day];
		int c2 = calc(day + 1, 0) + a[day];
		ans = max(c1, c2);
	}
	if (prev == 3) //first day: choose any
	{
		int c1 = calc(day + 1, 1) + b[day];
		int c2 = calc(day + 1, 2) + c[day];
		int c3 = calc(day + 1, 0) + a[day];
		ans = max(c1, max(c2, c3));
	}

	return dp[day][prev] = ans;

}


void solve()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << calc(0, 3);

}

int32_t main()
{
	fio();
	//setUpLocal();
	return solve(), 0;
}
