#include "bits/stdc++.h"

using namespace std;

#define int long long // −9·10^18 to 9·10^18
#define lll __int128_t
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'


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

// uncomment only for Codeforces. cpp-17
// template<typename... T>
// void read(T&... args) {
// 	((cin >> args), ...);
// }

// template<typename... T>
// void write(T&&... args) {
// 	((cout << args << " "), ...);
// }

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
#define sz(a) int((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"[i=n];
#define sortv(a) sort(a.begin(),a.end())


void fio()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
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
int pow(int a, int n, int mod)
{
	// a^n % mod
	int res = 1;
	while (n)
	{
		if (n & 1)
		{
			res = ((res % mod) * (a % mod)) % mod;
			n--;
		}
		else
		{
			a = ((a % mod) * (a % mod)) % mod;
			n /= 2;
		}
	}
	return res;
}

int ans(int a, int b , int n)
{
	if (a == b)
		return (pow(a, n, mod) + pow(b, n, mod)) % mod;

	int sec = a - b;

	int gcd = 1;
	for (int i = 1; i * i <= sec; i++)
	{
		if (sec % i == 0)
		{
			if ( (pow(a, n, i) + pow(b, n, i)) % i == 0)
			{
				gcd = max(gcd, i);
			}
			if ( (pow(a, n, sec / i) + pow(b, n, sec / i)) % (sec / i) == 0)
			{
				gcd = max(gcd, i);
				//deb(gcd);
			}
		}
	}

	return gcd % mod;

}

void solve()
{
	int a, b, n;
	w(t)
	{
		cin >> a >> b >> n;

		cout << ans(a, b, n) << endl;
	}

}

int32_t main()
{
	fio();
	return solve(), 0;
}
