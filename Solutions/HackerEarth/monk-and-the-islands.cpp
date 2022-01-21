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
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}

vi gp[100007];
int vis[100007];
int dist[100007];
int bfs(int strt, int dest)
{
	queue<int> q;
	q.push(strt);
	vis[strt] = 1;
	dist[strt] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int child : gp[cur])
		{
			if (!vis[child])
			{
				q.push(child);
				dist[child] = dist[cur] + 1;
				if (child == dest)
				{
					return dist[child];
				}
				vis[child] = 1;
			}
		}
	}
	return -1;
}
void solve()
{

	w(t)
	{
		int n, a, b; cin >> n;
		for (int i = 0; i < n; i++)
		{
			gp[i].clear(); vis[i] = 0; dist[i] = 0;
		}
		w(m)
		{
			cin >> a >> b; gp[a].pb(b); gp[b].pb(a);
		}
		cout << bfs(1, n) << endl;


	}
}

int32_t main()
{
	fio();
	return solve(), 0;
}
