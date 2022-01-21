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
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" ";
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

vi g[100007];
int vis[100007];
int dist[100007];
void dfs(int s, int count)
{
	vis[s] = 1; dist[s] = count;
	for (int child : g[s])
	{
		if (!vis[child])
		{
			//deb(child, s, dist[s]);
			dfs(child, dist[s] + 1);
		}
	}
}
void solve()
{
	int n, _n ; cin >> n; _n = n - 1;
	int s, d ;

	while (_n--)
		cin >> s >> d, g[s].pb(d),  g[d].pb(s);


	dfs(1, 0);

	//cout << dist[0] << dist[1] << dist[2] << dist[3] << dist[4];

	int ans = -1, min_dist = INF;
	w(q)
	{
		int city;
		cin >> city;
		if (dist[city] < min_dist)
			ans = city, min_dist = dist[city];
		else if (dist[city] == min_dist && city < ans)
			ans = city;
	}

	cout << ans << endl;


}

int32_t main()
{
	fio();
	return solve(), 0;
}
