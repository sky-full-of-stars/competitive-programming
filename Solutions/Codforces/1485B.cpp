#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include <bits/headerfile.hpp>
#else
#define dbg (...)
#endif

//---------------------------------------------------------------------------------------------------------//
using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define endl '\n'

//---------------------------------------------------------------------------------------------------------//
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;
typedef unordered_map<int, int> umi;

//---------------------------------------------------------------------------------------------------------//
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

//---------------------------------------------------------------------------------------------------------//
template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << " "), ...);
}

#ifndef ONLINE_JUDGE
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }
#else
#define debug(...) 1
#define cerr if(0) cerr
#endif

//---------------------------------------------------------------------------------------------------------//
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ipArr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define opArr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) (i.begin(),i.end())

//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;

int max(int a, int b) { return a >= b ? a : b;}
int min(int a, int b) { return a <= b ? a : b;}

void solve()
{
	int n, q, k;
	cin >> n >> q >> k;

	vi v(n + 1);
	vi choices(n + 2);
	v[0] = 0;
	choices[0] = 1;
	choices[n + 1] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int lowerBound = (i == 1) ? 1 : v[i - 1] + 1;
		int upperBound = (i == n) ? k : v[i + 1] - 1;
		int range = upperBound - lowerBound;
		choices[i] = range;

	}
	for (int i = 1; i <= n; i++)
	{
		choices[i] +=  choices[i - 1];
	}
	//debug(v, choices);

	while (q--)
	{
		int l, r;
		cin >> l >> r;
		if (l == r)
		{
			cout << k - 1 << endl;
			continue;
		}
		int ans = 1;
		int choicesForL = (v[l + 1] - 1 - 1);
		int choicesForR = (k - v[r - 1] - 1);
		l++; r--;
		int otherChoices = 0;
		if (l <= r)
			otherChoices = (choices[r] - choices[l - 1]);
		//debug(choicesForL, choicesForR, otherChoices);
		//cerr << endl;
		ans = choicesForL + choicesForR + otherChoices;
		cout << ans << endl;
	}

}
void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}
int32_t main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	setUpLocal();
	int t = 1; //cin>>t;
	while (t--) solve();
	return 0;
}
