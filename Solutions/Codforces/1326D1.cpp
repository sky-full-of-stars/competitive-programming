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

bool pal(string s)
{
	int l = 0;
	int r = sz(s) - 1;
	while (l <= r)
	{
		if (s[l] == s[r])
		{
			l++; r--;
		}
		else
		{
			return false;
		}
	}
	return true;
}
void solve()
{
	string s; cin >> s;
	int n = sz(s);

	if (n == 1)
	{
		cout << s << endl;
		return;
	}

	int l = 0; int r = n - 1;
	string middle = "";

	while (l <= r)
	{
		if (s[l] == s[r])
		{
			if (l == r)
			{
				middle = s[l];
			}
			l++;
			r--;
		}
		else
		{
			break;
		}
	}

	if (middle != "")
	{
		l--;
	}

	string common = s.substr(0, l);
	//debug(common, middle);

	if (l > r)
	{
		string reverse = string(common.rbegin(), common.rend());
		cout << common + middle + reverse << endl;
		return;
	}

	//debug(l, r);
	string rem = s.substr(l, n - 2 * l);
	//debug(rem);

	int lp = l;
	int rp = r;

	string palPre;
	bool found = false;
	while (lp <= rp)
	{
		char cur = s[lp];
		while (rp >= lp)
		{
			if (s[rp] == cur)
			{
				int len = rp - lp + 1;

				string pre = s.substr(lp, len);
				if (pal(pre))
				{
					palPre = pre;
					found = true;
					break;
				}
				else
				{
					rp--;
				}
			}
			else
			{
				rp--;
			}
		}
		break;
	}

	string palSuf;
	found = false;
	int ls = l, rs = r;

	char cur = s[rs];
	for (int i = ls; i <= rs; )
	{
		if (s[i] == cur)
		{
			int len = rs - i + 1;
			string suf = s.substr(i, len);
			if (pal(suf))
			{
				palSuf = suf;
				found = true;
				break;
			}
			else
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}

	string between = (sz(palPre) >= sz(palSuf)) ? palPre : palSuf;
	string reverse = string(common.rbegin(), common.rend());
	cout << (common + between + reverse) << endl;

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