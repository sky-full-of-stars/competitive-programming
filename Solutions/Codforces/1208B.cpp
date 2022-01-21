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

map<int, int> total;

bool ok(map<int, int> &rangeCount)
{
	for (auto i : total) {
		if (total[i.ff] == 1) { // distict element, so dont do anything

		}
		else {// non distinct elements should exist atleast count-1 times in range.
			if (rangeCount[i.ff] >= i.ss - 1) {

			}
			else {
				return false;
			}
		}
	}

	return true;
}

void solve()
{
	int n; cin >> n;
	vi a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total[a[i]]++;
	}

	bool distinct = true;
	for (auto i : total)
	{
		if (i.ss != 1)
		{
			distinct = false; break;
		}
	}
	if (distinct) {
		cout << 0 << endl;
		return;
	}


	int l = 0, r = 0;
	map<int, int> rangeCount;
	int ans = INF;
	bool isValidRange = false;


	// very bad coding I think, it shouldnt be this complicated.
	// ask someone's help && make it better.

	while (l < n)
	{
		while (r < n)
		{
			if (!isValidRange) // [l,r) isnt valid, so increment r
			{
				rangeCount[a[r]]++;
				r++;
			}
			if (ok(rangeCount))// [l,r) is valid
			{
				isValidRange = true;
				break;
			}

		}
		deb(r);

		int segLen = r - l;
		if (segLen < ans and isValidRange) {
			ans = segLen;
			cerr << l << " " << r << " " << ans << " ";
		}

		while (l < n) {

			rangeCount[a[l]]--;
			l++;

			if (ok(rangeCount))
			{
				isValidRange = true;
				break;
			}
			else {
				isValidRange = false;
				break;
			}
		}

		deb(l);
	}

	cout << ((ans <= 0) ? 0 : ans) << endl;

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
