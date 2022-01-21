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

const int maxN = 30;
// a ->97 z ->122

int dist[maxN][maxN];

void init()
{
	for (int i = 0; i < maxN; i++)
	{
		for (int j = 0; j < maxN; j++)
		{
			dist[i][j] = INF;
		}
	}
}

void solve()
{
	string x, y;
	cin >> x >> y;

	if (x.length() != y.length())
	{
		cout << -1 << endl;
		return;
	}

	int n; cin >> n;
	char u, v;
	int w;

	init();

	while (n--)
	{
		cin >> u >> v >> w;
		dist[u - 96][v - 96] = min(dist[u - 96][v - 96], w);
	}


	// fuck my debugging skills. pfft!

	// for (int i = 0; i < maxN; i++)
	// {
	// 	for (int j = 0; j < maxN; j++)
	// 	{
	// 		if (dist[i][j] >= INF)
	// 			cout << "INF" << " ";
	// 		else
	// 			cout << dist[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	//cerr << dist['a' - 96]['x' - 96] << " " << dist['x' - 96]['y' - 96] << endl;

	for (int k = 0; k < maxN; k++)
	{
		for (int i = 0; i < maxN; i++)
		{
			for (int j = 0; j < maxN; j++)
			{
				if (dist[i][k] >= INF or dist[k][j] >= INF)
				{
					continue;
				}
				else
				{
					//(i to j) implies (i to k)+(k to j)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					//cerr << char(i + 96) << " " << char(j + 96) << " " << char(k + 96) << endl;
				}
			}
		}
	}

	//cerr << dist['a' - 96]['x' - 96] << " " << dist['x' - 96]['y' - 96] << endl;

	vector<char> ans;
	int cost = 0;

	for (int i = 0; i < x.length(); i++)
	{
		char u = x[i];
		char v = y[i];

		if (u == v)
		{
			ans.pb(u);
			cont;
		}

		//check if (i,j) can be made (x,x) -> if(i,x) and (j,x) exists
		// and such cost is less than already available cost.

		int minAvailable = min(dist[u - 96][v - 96] , dist[v - 96][u - 96]);
		bool flag = false;
		int midNode;
		for (int k = 0; k < maxN; k++)
		{
			if (dist[u - 96][k] >= INF or dist[v - 96][k] >= INF)
				cont;
			if (dist[u - 96][k] + dist[v - 96][k] < minAvailable) // wow. ok!
			{
				midNode = k;
				minAvailable = dist[u - 96][k] + dist[v - 96][k];
				flag = true;
			}
		}
		if (flag)
		{
			cost += minAvailable;
			ans.pb((char)(midNode + 96));
			cont;
		}

		if (dist[u - 96][v - 96] >= INF and dist[v - 96][u - 96] >= INF)
		{
			cout << -1 << endl;
			return;
		}


		//FINALLY NORMAL CASE:

		//cerr << u << v << " " << dist[u][v] << " " << dist[v][u] << endl;
		// stop wrtiting ugly code like this to make it work ;-p
		(dist[u - 96][v - 96] < dist[v - 96][u - 96]) ?
		(cost += dist[u - 96][v - 96], ans.pb(v)) :
		(cost += dist[v - 96][u - 96], ans.pb(u)) ;
	}

	cout << cost << endl;
	for (char c : ans)
		cout << c;
	cout << endl;

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
