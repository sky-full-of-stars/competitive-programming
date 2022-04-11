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
int n, k;

bool check(int z, int o, int q)
{
	if (z > k / 2 or o > k / 2)
	{
		return false;
	}
	return true;
}

void solve()
{
	cin >> n >> k;
	string s; cin >> s;

	int z = 0, o = 0, q = 0;
	for (int j = 0; j < k; j++)
	{
		if (s[j] == '0')
			z++;
		else if (s[j] == '1')
			o++;
		else
			q++;
	}

	bool ok  = check(z, o, q);
	if (!ok)
	{
		cout << "NO" << endl;
		return;
	}

	for (int i = 1; i < n - k + 1; i++)
	{
		char del = s[i - 1];
		char add = s[i + k - 1];
		//debug(del, add);

		if (del == add)
		{
			continue;
		}
		if ((del == '1' and add == '0') or (del == '0' and add == '1'))
		{
			cout << "NO" << endl;
			return;
		}
		else // has one '?' and 0/1
		{
			if (del == '?')
			{
				if (add == '1')
					o++, q--;
				else
					z++, q--;

				bool ok  = check(z, o, q); //really possible to substitute?
				if (!ok)
				{
					cout << "NO" << endl;
					return;
				}
			}
			else if (add == '?')
			{
				if (del == '1')
				{
					if (s[i + k - 1] == '?') // necessary or safeplay?
					{
						s[i + k - 1] = '1';
					}
					else
					{
						cout << "NO" << endl;
						return;
					}
				}
				else
				{
					if (s[i + k - 1] == '?')
					{
						s[i + k - 1] = '0';
					}
					else
					{
						cout << "NO" << endl;
						return;
					}
				}
			}
		}

	}

	cout << "YES" << endl;
	return;




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