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

//so that they get initialized to 0
int len1[26];
int len2[26][26];

void solve()
{
	string s; cin >> s;

	//idea: https://codeforces.com/blog/entry/73953?#comment-670505

	// we can have only strings of len1 and len2 in optimal string
	// if we have string of len>2 then that means we also have the same occurance or more of len 2
	// if we have akbkck repeated some 5 times that means, we also have akbk repeated 5 times or more
	// so lets only calculate strings occurances of len1 and len2
	// len1 string count is easy
	// go over each idx and increment its count
	// for len2 string. at every idx think that its second char of string of len2 we want.
	// first char for that string can be anything which we've seen before
	// so, if cur char is 'c' we are forming string of 'kc' where k is any character.
	// so if cur char is 'c' then, we have count[k][c] += count[c] where c has occured before current idx
	// so go over all chars, get counts of all str of len 1 and 2 and find max
	// one more point to note is while counting string of len 2, we consider first char as a character which we've seen before
	// so while doing, count[k][c] += count[c] make sure count[c] doesnt include current character & you'll be good.

	int n = sz(s);

	for (int i = 0; i < n; i++)
	{
		int cur = s[i] - 'a';

		for (int i = 0; i < 26; i++)
		{
			len2[i][cur] += len1[i];
		}

		len1[cur]++;
	}

	int mx = 1;
	for (int i = 0; i < 26; i++)
	{
		mx = max(mx, len1[i]);
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			mx = max(mx, len2[i][j]);
		}
	}

	cout << mx << endl;
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