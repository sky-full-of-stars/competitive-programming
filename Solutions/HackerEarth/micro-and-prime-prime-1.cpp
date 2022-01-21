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
#define print_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i];
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

const int maxN = 1000007;

int cum[maxN];
bool pri[maxN];
int pripri[maxN];
void sieve()
{
	fill(pri, pri + maxN, true);
	pri[0] = pri[1] = false;
	for (int i = 4; i <= maxN; i += 2)
		pri[i] = false;
	for (int i = 2; i * i <= maxN; i++)
	{
		if (pri[i])
		{
			for (int j = i * i; j <= maxN; j += (2 * i))
			{
				pri[j] = false;
			}
		}
	}
}
void calCum()
{
	cum[1] = 0;
	cum[2] = 1;
	cum[3] = 2;
	int prev = cum[3];
	for (int i = 4; i <= maxN; i++)
	{
		if (pri[i])
		{
			cum[i] = prev + 1;
			prev = cum[i];
		}
		else
		{
			cum[i] = prev;
		}
	}

}

bool ispripri(int n)
{
	if (pri[cum[n]])
		return true;
	return false;
}

void calPriPri()
{
	pripri[0] = 0;
	pripri[1] = pripri[2] = 0;
	pripri[3] = 1;
	for (int i = 4; i <= maxN; i++)
	{
		if (ispripri(i))
		{
			pripri[i] = pripri[i - 1] + 1;
		}
		else
		{
			pripri[i] = pripri[i - 1];
		}
	}
}
void solve()
{
	sieve();
	calCum();
	calPriPri();
	int l, r;
	w(t)
	{
		cin >> l >> r;
		cout << (pripri[r] - pripri[l - 1]) << endl;
	}

}

int32_t main()
{
	fio();
	return solve(), 0;
}
