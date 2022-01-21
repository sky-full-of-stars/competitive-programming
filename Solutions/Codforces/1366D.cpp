#include "bits/stdc++.h"

using namespace std;

#define int long long
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
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define op_arr(arr,n) for(int i=0;i<n;i++) {cout<<arr[i]<<" ";if(i==n-1)cout<<endl;}
#define fill_arr(arr,n,i) fill(arr,arr+n,i);
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
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

const int maxN = 1e3 + 7;
int primes[maxN];
int spf[maxN];
vi d1, d2;

void sieve(int n)
{
	fill_arr(primes, n, true);
	for (int i  = 1; i < n; i++)
		spf[i] = i;
	primes[0] = primes[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (primes[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				if (primes[j])
				{
					primes[j] = false;
					spf[j] = i;
				}
			}
		}
	}
}
void find(int n)
{
	int sf = spf[n];
	//deb(n, sf);
	int _n = n;
	int div1 = -1, div2 = -1;
	while (_n % sf == 0)
	{
		_n /= sf;
	}
	if (_n == 1)
	{
		d1.pb(div1);
		d2.pb(div2);
		deb(n, div1, div2); cerr << endl;
	}
	else
	{
		div1 = sf;
		div2 = _n ;
		deb(n, div1, div2); cerr << endl;
		d1.pb(div1);
		d2.pb(div2);
	}

}
void solve()
{
	sieve(maxN);
	w(t)
	{
		int n; cin >> n;
		find(n);
	}
	op_arr(d1, d1.size());
	op_arr(d2, d2.size());

}

int32_t main()
{
	fio();
	return solve(), 0;
}
