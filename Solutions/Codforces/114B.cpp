#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define mpp make_pair
#define endl '\n'
#define isBitSet(var,pos) ((var) & (1<<(pos)))

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


const int maxn = 20;
int n, m;
map<string, int> mp;
map<int, string> revmp;
int gp[maxn][maxn];
vi ans;

bool check(vi v)
{
	for (int i : v)
		for (int j : v)
			if (gp[i][j])
				return false;
	return true;
}

bool comp(int i, int j)
{
	return revmp[i] < revmp[j];
}
void solve()
{
	cin >> n >> m;

	int cnt = -1;
	int _n = n;
	while (_n--)
	{
		string s; cin >> s;
		mp[s] = ++cnt;
		revmp[cnt] = s;
	}

	string u, v;
	while (m--)
	{
		cin >> u >> v;
		gp[mp[u]][mp[v]] = 1;
		gp[mp[v]][mp[u]] = 1;
	}

	for (int i = 1; i < (1 << n); i++)
	{
		vi v;
		for (int j = 0; j < n; j++)
		{
			if (isBitSet(i, j))
				v.pb(j);
		}
		//cerr << v.size() << endl;
		if (v.size() > ans.size())
			if (check(v))
				ans = v;
	}

	cout << ans.size() << endl;

	sort(ans.begin(), ans.end(), comp);
	for (int i : ans)
		cout << revmp[i] << endl;


}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
