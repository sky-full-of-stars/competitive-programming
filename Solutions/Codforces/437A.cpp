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

const int gp_size = (int)1e6 + 7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

void solve()
{

	string a, b, c, d;
	int p, q, r, s;
	read(a, b, c, d);
	p = a.length() - 2;
	q = b.length() - 2;
	r = c.length() - 2;
	s = d.length() - 2;


	char ans = 'C';
	int cnt = 0;
	if ((2 * q <= p and r * 2 <= p and s * 2 <= p) or (q >= 2 * p and r >= 2 * p and s >= 2 * p))
	{
		ans = 'A'; cnt++;
	}
	if ((p * 2 <= q and r * 2 <= q and s * 2 <= q) or (p >= 2 * q and r >= 2 * q and s >= 2 * q))
	{
		ans = 'B'; cnt++;
	}
	if ((p * 2 <= r and q * 2 <= r and s * 2 <= r) or (p >= 2 * r and q >= 2 * r and s >= 2 * r))
	{
		ans = 'C'; cnt++;
	}
	if ((q * 2 <= s and r * 2 <= s and p * 2 <= s) or (q >= 2 * s and r >= 2 * s and p >= 2 * s))
	{
		ans = 'D'; cnt++;
	}

	deb(p, q, r, s, ans, cnt);

	if (cnt == 1)
		cout << ans;
	else
		cout << "C";

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}