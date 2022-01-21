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


const int maxN = 1007;

map<int, int> sub; //<idx, endIdxOfPerfectSequenceFromi)

void populateSub(int i, string &s)
{
	int start = i;

	stack<char> stk;
	stk.push(s[i]);
	i++;
	while (sz(stk) and i < sz(s))
	{
		if (s[i] == ')')
		{
			stk.pop();
		}
		else if (s[i] == '(')
		{
			stk.push(s[i]);
		}
		else
		{
			// do nothin for + and 1
		}
		i++;
	}

	int end = i;

	// vector<char> subv;
	// for (int i = start; i < end; i++)
	// {
	// 	subv.pb(s[i]);
	// }
	sub[start] = end;

}

vi ans;
//int memo[maxN][maxN];
bool findSubSeqSum(vi &v, int sum, int start)
{
	if (sum == 0)
		return true;
	if (start >= sz(v))
		return false;
// 	if (memo[sum][start] != -1)
// 		return memo[sum][start];
	if (v[start] <= sum)
	{
		//include
		ans.pb(v[start]);
		return findSubSeqSum(v, sum - v[start], start + 1);

		//exclude
		return findSubSeqSum(v, sum, start + 1);
	}
	else
	{
		//exclude
		return findSubSeqSum(v, sum, start + 1);
	}
	return false;

}

string getString(int start, int end, string s)
{
	string ans = "";
	for (int i = start; i < end; i++)
		ans += s[i];
	return ans;
}

// I assumed string can be like (1+1+1+1+1+1)(())(1+1) and so on.
// actual problem was pretty simple. it was only brackets.
void solve()//plis TLEEEEE
{
	int n, k; read(n, k);
	string s; read(s);

	if (n == k) {
		cout << s << endl; return;
	}

	vi subLen;
	map<int, vi> sizeToIdx;
	for (int i = 0; i < sz(s); i++)
	{
		if (s[i] == '(')
		{
			populateSub(i, s);
			subLen.pb(sub[i] - i);
			sizeToIdx[sub[i] - i].pb(i);
		}
	}

	//memset(memo, -1, sizeof memo);
	findSubSeqSum(subLen, k, 0); //plis TLEEEEE
	si used;

	for (int i : ans) {
		vi indices = sizeToIdx[i];
		int idx;
		for (int &i : indices)
			if (!present(used, i))
			{
				idx = i; break;
			}

		debug(idx);
		cout << getString(idx, sub[idx], s);
		used.insert(idx);
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
