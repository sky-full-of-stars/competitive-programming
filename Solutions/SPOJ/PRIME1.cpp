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
#define gcd(x,y) return __gcd(x,y);
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
}

const int gp_size = (int)1e6 + 7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

//sqrt(1000000000)=31622.7
const int maxN = 32000;
int primes[maxN];
vi primeNum;

void init (int l, int r)
{
	// 40 to 100 or 41 to 100
	// 2,3,5,7: p(i)
	if (l == 1)
		l++;
	vi rangePrimes((r - l + 1), 1); // all are primes: init
	for (int i : primeNum)
	{
		if (i * i <= r)
		{
			int firMul = (int)(l / i) * i;
			if (firMul < l)
			{
				firMul += i;
			}

			for (int j = firMul; j <= r; j += i) //j: 40,42,44....100 ->composite
			{
				if (j != i)
					rangePrimes[j - l] = 0;
			}
		}
	}
	for (int i = 0; i < r - l + 1; i++)
	{
		if (rangePrimes[i])
			cout << l + i << endl;
	}


}
void sieve()
{
	fill(primes, primes + maxN, 1); // all are primes: init
	for (int i = 2; i * i <= maxN; i++)
	{
		if (primes[i] == 1)
		{
			for (int j = i * i ; j <= maxN; j += i)
			{
				primes[j] = 0; // composite
			}
		}
	}

	for (int i = 2; i <= maxN; i++)
	{
		if (primes[i])
			primeNum.pb(i);
	}
}
void solve()
{
	sieve();
	int l, r;
	w(t)
	{
		cin >> l >> r;
		init(l, r);
		cout << endl;
	}
}

int32_t main()
{
	fio();
	return solve(), 0;
}
