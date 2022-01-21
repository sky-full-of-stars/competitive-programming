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
#define sz(a) int((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(ll i=0;i<n;i++) cin>>a[i];
#define print_arr(arr,n) for(ll i=0;i<n;i++) cout<<arr[i]<<"\n"[i=n];
#define sortv(a) sort(a.begin(),a.end())


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


vi gp[2002];
int vis[2002];
int clr[2002];


bool isBipartile(int st, int col)
{
	vis[st] = 1;
	clr[st] = col;
	for (int child : gp[st])
	{
		if (!vis[child])
		{
			if (!isBipartile(child, !col))
				return false;
		}
		else
		{
			if (clr[child] == clr[st])
				return false;
		}
	}
	return true;
}

void solve()
{
	int sc = 0;

	w(t)
	{
		sc++;
		cout << "Scenario #" << sc << ":" << endl;

		int n; cin >> n;
		bool ans = true;
		for (int i = 0; i <= n ; i++)
			gp[i].clear();
		fill(vis, vis + n + 1, 0);
		fill(clr, clr + n + 1, 0);
		w(m)
		{
			int a, b;
			cin >> a >> b, gp[a].pb(b), gp[b].pb(a);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				ans = isBipartile(i, 0);
				if (!ans)
					break;
			}
		}
		if (!ans)
			cout << "Suspicious bugs found!" << endl;
		else
			cout << "No suspicious bugs found!" << endl;
	}

}

int32_t main()
{
	fio();
	return solve(), 0;
}
