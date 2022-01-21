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
#endif
}

const int maxN = 1e7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];
void solve()
{
	int n, i;
	cin >> n >> i;
	vi a(n);
	map<int, int> freq;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		freq[a[i]]++;
	}

	int power = (8 * i) / n;
	int dist ;
	if (power >= 20)
		dist = n;
	else
		dist = (int) pow(2, power);

	if (dist >= n) {
		cout << 0 << endl;
		return;
	}


	// consider subarray of k distinct elements
	// now to get each range (l,r)
	// calculate num of elemtents considered
	// then calculate number of elements left out
	// minimize such number

	int l = 0, r = 0;

	set<int> s; // set of unique elements from l to r;

	sortv(a);

	int ans = INF;
	while (l < n) {

		while (r < n and sz(s) <= dist) {
			s.insert(a[r]);
			r++;
		}

		if (sz(s) == dist + 1) { //find a better way to do this
			if (r < n)
				s.erase(a[r]);
			r--;
		}

		int count = r - l; //count of elements considered in range [l,r)
		int modified = n - count;

		//cerr << l << " " << r << endl;

		if (modified < ans)
			ans = modified;

		int previous = a[l];
		while (l < n and a[l] == previous) { //find a better way to do this
			l++;
		}
		s.erase(a[l - 1]);
	}

	cout << ans << endl;
}

int32_t main()
{
	fio();
	setUpLocal();
	int t;
	t = 1;
	while (t--)
		solve();
	return 0;
}