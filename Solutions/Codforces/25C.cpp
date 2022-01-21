#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define mp make_pair
#define endl '\n'


typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

//const
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

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

#ifndef ONLINE_JUDGE
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define deb(...) 1
#define cerr if(0) cerr
#endif

//useful functions
//#define deb(x) cout<<#x<<": "<<x<<endl;
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define op_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())

void fio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#else
#define cerr if(0) cerr
#endif
}


int dist[303][303];
int n;

void init()
{
	for (int i = 0; i <= n + 2; i++)
	{
		for (int j = 0; j <= n + 2; j++)
		{
			dist[i][j] = INF;
		}
	}
}

void flWrsh()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (dist[i][k] == INF or dist[k][j] == INF)
				{
					cont;
				}
				else
				{
					//cerr << dist[1][2] << " " << dist[1][3] + dist[3][2];
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					dist[j][i] = dist[i][j];
				}
			}
		}
	}
}

void flWrshNrml(int u, int v)
{
	vi nodes; nodes.pb(u); nodes.pb(v);
	for (int k : nodes)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (dist[i][k] == INF or dist[k][j] == INF)
				{
					cont;
				}
				else
				{
					//cerr << dist[1][2] << " " << dist[1][3] + dist[3][2];
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					dist[j][i] = dist[i][j];
				}
			}
		}
	}
}

int ans;
void getAns()
{
	int sum = 0;
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			sum += dist[i][j];
	ans = sum;
}

void disp()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cerr << dist[i][j] << " ";
		cerr << endl;
	}
	cerr << "____________________" << endl;;
}
void solve()
{

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dist[i][j];

	int k;
	cin >> k;

	flWrsh();
	getAns();

	while (k--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (dist[u][v] < w)
		{
			cout << ans << " ";
			continue;
		}
		else
		{
			dist[u][v] = w;
			dist[v][u] = w;
			//disp();
			flWrshNrml(u, v);
			//disp();
			getAns();
			cout << ans << " ";
		}
	}
}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
