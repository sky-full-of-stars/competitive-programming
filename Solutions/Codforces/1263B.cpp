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
#define opArr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()

int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
bool isPowOfTwo(int x) {return (x && (!(x & (x - 1))));}
//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;

vi getAlt(int n)
{
	vi v;
	int rem = n % 10;
	n -= rem;
	for (int i = 0; i < 10; i++)
	{
		v.pb(n + i);
	}
	return v;
}
string getString(int i)
{
	string n = to_string(i);
	string ans = "";
	int cnt = 4 - sz(n);
	for (int i = 0; i < cnt; i++)
		ans += "0";
	ans += n;
	return ans;
}
void solve()
{
	int l; cin >> l;
	vector<string> v(l);
	ipArr(v, l);

	set<string> ans;
	map<string, int> count;
	for (string i : v)
	{
		count[i]++;
	}
	vector<string> final;
	int c = 0;
	for (string st : v)
	{
		int i = stoi(st);
		if (count[getString(i)] == 1)
		{
			ans.insert(getString(i));
			final.pb(getString(i));
			continue;
		}
		if (!present(ans, getString(i))) //1st occurance, you can keep
		{
			ans.insert(getString(i));
			final.pb(getString(i));
			continue;
		}
		vi alt = getAlt(i);
		for (int j : alt)
		{
			if (count[getString(j)] == 0)
			{
				ans.insert(getString(j));
				final.pb(getString(j));
				count[getString(j)]++;
				c++;
				break;
			}
		}
	}
	cout << c << endl;
	if (!c)
	{
		for (string i : v)
			cout << i << endl;
		return;
	}
	for (string i : final)
	{
		cout << i << endl;
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
	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}