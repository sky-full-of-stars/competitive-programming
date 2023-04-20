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
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ipArr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define opArr(arr,n) for(int i=0;i<n;i++) cerr<<arr[i]<<" ";
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()

int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
bool isPowOfTwo(int x) {return (x && (!(x & (x - 1))));}
//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;

void solve()
{
	int n; cin >> n;
	int _n = n;
	mi m;
	int ele;
	while (n--)
	{
		cin >> ele;
		m[ele]++;
	}

	vi freq;
	for (auto [key, cnt] : m)
	{
		freq.pb(cnt);
	}
	sortv(freq);
	reverse(all(freq));
	int mn = INF;

	int sz = sz(freq);
	int suffix[sz];
	suffix[0] = freq[0];
	for (int i = 0; i < sz; i++)
	{
		if (i != 0)
			suffix[i] = suffix[i - 1] + freq[i];

		if (i == sz - 1 or freq[i] != freq[i + 1])
		{
			int expect = (i + 1) * freq[i];
			int actual = suffix[i];
			int excess = actual - expect;

			int lowerFreq = (_n - suffix[i]);

			int currentAns = excess + lowerFreq;
			mn = min(mn, currentAns);
		}
	}
	cout << mn << endl;
}
/*

4 3 3  2  2  1  -> freq
4 7 10 12 14 15 -> suffixSum


5 5  4  3  3   2  2  2  1 ->freq
5 10 14 17 20 22 24 26 27 ->suffix
3 3  3  3  3

At last occurance of '3':
	expect -> 15 (if all elem were repeated 3 times)
	actual -> 20 (count of reality)
	excess -> 5

	toRemoveLesserFreq -> (n- suf[i]);

ans = excess + toRemoveLesserFreq

*/
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
	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}