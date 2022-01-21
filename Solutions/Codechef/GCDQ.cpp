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
#define print_arr(arr,n) for(int X=0;X<n;X++) cout<<arr[X]; cout<<endl;
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

int maxN = 101;
vi v;
vi pre(maxN);
vi suf(maxN);

int gcd(int a, int b)
{
	if (!b) return a;
	else return gcd(b, a % b);
}


void preComp()
{
	int sz = v.size();
	pre[0] = v[0];
	for (int i = 1; i < sz; i++)
	{
		pre[i] = gcd(pre[i - 1], v[i]);
	}
	suf[sz] = 0;
	suf[sz - 1] = v[sz - 1];
	for (int i = sz - 2; i >= 0; i--)
	{
		suf[i] = gcd(suf[i + 1], v[i]);
	}
}



int rangeGCD(int l, int r)
{
	// l=3 r=5
	// gcd(1,2,6,7);
	// gcd(pre(l-1), suf(r+1))

	return gcd(pre[l - 1], suf[r + 1]);
}
void solve()
{
	int n, q;
	int l, r;
	int a;
	w(t)
	{
		cin >> n >> q;
		v.clear();
		while (n--)
		{
			cin >> a;
			v.pb(a);
		}
		preComp();
		while (q--)
		{
			cin >> l >> r;
			l--; r--;
			cout << rangeGCD(l, r) << endl;
		}
	}
}

int32_t main()
{
	fio();
	return solve(), 0;
}
