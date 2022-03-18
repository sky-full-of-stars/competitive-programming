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

const int maxN = 1e3 + 3;
int n, m;


int par1[maxN]; // keep track of parent
int siz1[maxN]; // keep track of size

int par2[maxN]; // keep track of parent
int siz2[maxN]; // keep track of size


void init1()// init with size arr and par arr
{
	for (int i = 1; i <= n; i++)
	{
		par1[i] = i;
		siz1[i] = 1;
	}
}
void init2()// init with size arr and par arr
{
	for (int i = 1; i <= n; i++)
	{
		par2[i] = i;
		siz2[i] = 1;
	}
}

int root1(int u) // path compression
{
	int rootU = u;
	while (par1[rootU] != rootU)
	{
		rootU = par1[par1[rootU]]; //halving len of path
	}

	return rootU;
}
int root2(int u) // path compression
{
	int rootU = u;
	while (par2[rootU] != rootU)
	{
		rootU = par2[par2[rootU]]; //halving len of path
	}

	return rootU;
}


int c = 0;
void weightedUnion1(int u, int v) // weighted union
{
	int rootU = root1(u);
	int rootV = root1(v);

	//cerr << rootU << " " << rootV << " " << siz[rootU] << " " << siz[rootV] << " ";

	if (siz1[rootU] <= siz1[rootV])
	{
		par1[rootU] = rootV;
		siz1[rootV] += siz1[rootU];
	}
	else
	{
		par1[rootV] = rootU;
		siz1[rootU] += siz1[rootV];
	}
}

void weightedUnion2(int u, int v) // weighted union
{
	int rootU = root2(u);
	int rootV = root2(v);

	//cerr << rootU << " " << rootV << " " << siz[rootU] << " " << siz[rootV] << " ";

	if (siz2[rootU] <= siz2[rootV])
	{
		par2[rootU] = rootV;
		siz2[rootV] += siz2[rootU];
	}
	else
	{
		par2[rootV] = rootU;
		siz2[rootU] += siz2[rootV];
	}
}

bool find1(int u, int v)
{
	return (root1(u) == root1(v));
}
bool find2(int u, int v)
{
	return (root2(u) == root2(v));
}

void display()
{
	vi v;
	map<int, int> visRoots;

	for (int i = 1; i <= n; i++)
	{
		int rootI = root1(i);
		if (!visRoots[rootI])
		{
			v.pb(siz1[rootI]);
			visRoots[rootI] = 1;
		}
	}

	sort(v.begin(), v.end());
	for (int i : v)
		cout << i << " ";
}

set<pair<int, int>> ans;
void addValidEdges()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (!find1(i, j) and !find2(i, j))
			{
				//cerr << i << " " << j << " " << root1(i) << " " << root1(j) << " " << root2(i) << " " << root2(j) << endl;
				weightedUnion1(i, j);
				weightedUnion2(i, j);
				ans.insert({i, j});
			}
		}
	}
}
void solve()
{
	cin >> n;

	init1();
	init2();

	int m1, m2; cin >> m1 >> m2;
	while (m1--)
	{
		int u, v;
		cin >> u >> v;
		weightedUnion1(u, v);
	}

	while (m2--)
	{
		int u, v;
		cin >> u >> v;
		weightedUnion2(u, v);
	}

	addValidEdges();

	cout << sz(ans) << endl;
	for (auto i : ans)
	{
		cout << i.ff << " " << i.ss << endl;
	}
}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
