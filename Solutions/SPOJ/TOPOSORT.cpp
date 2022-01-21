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
vi gp[gp_size];
int vis[gp_size];
int cnt[gp_size];
int ind[gp_size];

vector<int> order;
bool toposort(int n)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++)
	{
		if (!ind[i])
			pq.push(i);
	}
	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		order.pb(cur);

		for (int child : gp[cur])
		{
			ind[child]--;
			if (!ind[child])
				pq.push(child);
		}
	}

	if (order.size() == n)
		return true;
	return false;



}
void solve()
{

	int n, m; cin >> n >> m;
	int a, b;
	while (m--)
	{
		cin >> a >> b;
		gp[a].pb(b); ind[b]++;
	}

	if (toposort(n))
	{
		for (int i : order)
		{
			cout << i << " ";
		}
		return;
	}
	cout << "Sandro fails.";
}

int32_t main()
{
	fio();
	return solve(), 0;
}
