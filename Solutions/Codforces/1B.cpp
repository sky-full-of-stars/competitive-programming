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

int max(int a, int b)
{
	return a >= b ? a : b;
}
char intToChar(int c)
{
	return (char)(c + 64);
}
int charToInt(char c)
{
	return (int)(c - 'A' + 1);
}

bool rcformat(string s)
{
	bool lettersOver = false;
	for (int i = 0; i < sz(s); i++)
	{
		char c = s[i];
		if (!isdigit(c))
		{
			if (!lettersOver)
			{
				continue;
			}
			else
			{
				return true;
			}

		}
		else
		{
			if (!lettersOver)
			{
				lettersOver = true;
			}
			else
			{
				continue;
			}
		}
	}
	return false;
}

pi getRC(string s)
{
	int i = 1;
	while (isdigit(s[i]))
	{
		i++;
	}
	int row = stoi(s.substr(1, i));
	i++;
	int col = stoi(s.substr(i, sz(s)));
	return {row, col};
}

string getCol(int c)
{
	string s2 = "";

	while (c)
	{
		int rem = c % 26;
		if (rem)
		{
			s2 = intToChar(rem) + s2;
			c /= 26;
		}
		else
		{
			s2 = "Z" + s2;
			c /= 26;
			c--;
		}

	}
	return s2;
}
string f1(string s)
{
	pi rowcol = getRC(s);
	string col = getCol(rowcol.ss);
	return col + to_string(rowcol.ff);
}

pair<string, int> getRC2(string s)
{
	int i = 0;
	while (!isdigit(s[i]))
	{
		i++;
	}
	string row = s.substr(0, i);
	int col = stoi(s.substr(i, sz(s)));
	return {row, col};
}
string f2(string s)
{
	pair<string, int> rowcol = getRC2(s);

	int col = 0;
	int multiple = 1;
	string colS = rowcol.ff;
	for (int i = sz(colS) - 1; i >= 0; i--)
	{
		int val = charToInt(colS[i]);
		col += (multiple * val);
		multiple *= 26;
	}
	string row = to_string(rowcol.ss);
	return "R" + row + "C" + to_string(col);
}

void solve()
{
	string s; cin >> s;

	if (rcformat(s))
	{
		cout << f1(s);
	}
	else
	{
		cout << f2(s);
	}
	cout << endl;
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