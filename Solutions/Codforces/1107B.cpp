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

#ifndef ONLINE_JUDGE
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define deb(...) 1
#define cerr if(0) cerr
#endif

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
#endif
}

const int maxN = 1e7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

int digitSum(int x)
{
	string xx = to_string(x);

	int sum = 0;
	while (true)
	{
		sum = 0;
		for (char i : xx) {
			sum += (int)i - '0';
		}
		xx = to_string(sum);

		if (xx.length() == 1)
		{
			break;
		}
	}
	return sum;
}
void solve()
{
	int k, x; cin >> k >> x;

	// soln 1
	cout << x + 9ll * (k - 1) << endl;
	return;

	//soln 2
	int lo = 0;
	int count = 0;
	while (true)
	{
		if (lo % 9 == x) {
			count++; lo++;
		}
		else lo++;
		if (count == k) {
			cout << lo - 1 << endl;
			return;
		}
	}

	// soln 3
	int i = x;
	int ans = 0;

	while (true)
	{
		if (digitSum(i) == x) {
			ans++;
			i++;
		}
		else {
			i++;
		}
		if (ans == k)
		{
			cout << i - 1 << endl;
			return;
		}
	}
}

int32_t main()
{
	fio();
	setUpLocal();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
