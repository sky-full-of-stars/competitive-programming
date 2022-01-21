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
#define EPS LLONG_MIN
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
#endif
}

const int maxN = 1e7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];
void solve()
{
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;
		vi a(n);
		vi eligible;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int l = 0, r;
		int best = 0;
		while (l < n)
		{
			if (a[l] < 0) {
				r = l + 1;
				best = a[l];
				while (r < n and a[r] < 0) {
					best = max(best, a[r]);
					r++;
				}
				eligible.pb(best);
				l = r;
			}
			if (l >= n)
				continue;
			if (a[l] > 0) {
				r = l + 1;
				best = a[l];
				while (r < n and a[r] > 0) {
					best = max(best, a[r]);
					r++;
				}
				eligible.pb(best);
				l = r;
			}
		}

		// correct input : 2 1 -79 1 75
		// everything works fine. I'm ok.



		// for this erroneous input : 3 1 -79 1 75 (3 testcases expected only 2 provided)

		//if the below cerr statement is commented, sublime text runs the program forever.
		//(probably waiting for input?) ok. debug screen output: 1 1)

		//if the below cerr statement is present, sublime text returns  output for 1st case and doesnt print anything for 2nd case
		//why is 2nd case output not printed?(debug screen output: 1 1)

		//if input is modified to correct input : 2 1 -79 1 75. then correct op is printed.

		//cerr << "1" << " ";






		//for (int i : eligible) cerr << i << " ";

		cout << accumulate(eligible.begin(), eligible.end(), 0LL) << endl;

	}
}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
