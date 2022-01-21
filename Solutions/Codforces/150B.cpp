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

const int maxN = 2 * 1e3;
const int gp_size = maxN;
vi gp[gp_size];
int vis[gp_size];
int cnt[gp_size];


// SOLUTION: adding this explaination just in case if it might help someone

// first we take each position(char) of string len 'n' as node
// then we construct edges to indicate that all 'k' len subsets are palindromes.
// we do that by adding edges to such elements which are supposed to be equal

// then connected component indicates, all nodes there should have same value.
// we've e connected components
// we can put one of m values in each cc.

// so total number of such choices is:

// for first cc we can put any one of m values
// for second cc we can put any one of m values
// and so on..

// so total number of choices are m*m*m....e times
// = m^e

// n = 5, m = 2, k = 3
// Consider 1-based indexing.

// For the first substring [1, 3]:
// 1 and 3, 2 and 2 have to be the same. So you merge 1 with 3, 2 with 2.

// Now for the second substring [2, 4]:
// 2 and 4, 3 and 3 have to be the same. So you merge 2 with 4, 3 with 3.

// Now for the third substring [3, 5]:
// 3 and 5, 4 and 4 have to be the same. So you merge 3 with 5, 4 with 4.

// Finally we have two disjoint sets:= 1-3-5 and 2-4

// So the answer is m^2 = 4.

void dfs(int i)
{
	vis[i] = 1;
	for (int child : gp[i])
		if (!vis[child])
			dfs(child);
}

int modPow(int n, int k) {
	int ret = 1;
	while (k)
	{
		if (k & 1)
			ret = ret * n % mod;
		k >>= 1;
		n = n * n % mod;
	}
	return ret;
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	// if (k > n)
	// {
	// 	cout << 0 << endl; // !true : 2 3 3 -> aaa bbb ccc are valid here
	// 	return;
	// }

	for (int i = 1; i <= n - k + 1; i++)
	{
		for (int f = i, b = i + k - 1; f <= b; f++, b--) // frwd, bckward
		{
			//cerr << f << " " << b << endl;
			gp[f].pb(b);
			gp[b].pb(f);
		}
		//cerr << endl;
	}


	int cc = 0; // connected components
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			cc++;
			dfs(i);
		}
	}

	//cerr << cc;

	cout << modPow(m, cc);

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
