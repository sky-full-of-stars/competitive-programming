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

void solve()
{

	int n = 0; cin >> n;
	vi st(n , 0);
	w(m)
	{
		int a, b; cin >> a >> b;
		if (a == 1 && b == 0)
		{
			cout << -1 << endl; return;
		}
		else if (st[a - 1] != 0 && st[a - 1] != b)
		{
			cout << -1 << endl; return;
		}
		else if (st[a - 1] == 0)
		{
			st[a - 1] = b;
		}
	}
	for (auto i : st)
		cout << i;
	cout << endl;

}

int32_t main()
{
	fio();
	return solve(), 0;
}
