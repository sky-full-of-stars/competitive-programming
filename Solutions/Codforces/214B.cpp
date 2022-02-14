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

void solve()
{
	int n; cin >> n;

	vi digits(n);
	bool has0 = false;
	int sum = 0;
	map<int, si> rem;
	int countOf1 = 0;
	int countOf2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> digits[i];

		rem[digits[i] % 3].insert(digits[i]);
		sum += digits[i];
		if (digits[i] == 0)
			has0 = true;

		//hack
		if (digits[i] % 3 == 1)
		{
			countOf1++;
		}
		if (digits[i] % 3 == 2)
		{
			countOf2++;
		}

	}

	if (!has0)
	{
		cout << -1 << endl;
		return;
	}

	sort(all(digits), greater<int>());
	int extra = sum % 3;

	if (!extra)
	{
		if (!digits[0])
		{
			cout << 0 << endl;
			return;
		}
		for (int i : digits)
		{
			cout << i;
		}
	}
	else if (extra == 1)
	{
		if (sz(rem[1]) == 0 and  countOf2 < 2)
		{
			cout << 0 << endl;
			return;
		}
		else
		{
			if (sz(rem[1]) >= 1) // remove lesser number of digits
			{
				int eleToRmv = *(rem[1].begin());
				bool foundNonZero = false;
				int count = 1;
				for (auto i : digits)
				{
					if (i == eleToRmv and count)
					{
						count--;
					}
					else if (i)
					{
						foundNonZero = true;
						break;
					}
				}
				if (foundNonZero)
				{
					bool selected = false;
					for (int i : digits)
					{
						if (i == eleToRmv and !selected)
						{
							selected = true; continue;
						}
						else
						{
							cout << i;
						}
					}
				}
				else
				{
					cout << 0 << endl;
				}
			}
			else
			{
				int ele1 = -1, ele2 = -1;
				for (auto i = digits.rbegin(); i != digits.rend(); i++)
				{
					int ele  = *i;
					if (ele % 3 == 2 and ele1 == -1)
					{
						ele1 = ele;
					}
					else if (ele % 3 == 2 and ele2 == -1)
					{
						ele2 = ele;
					}
					if (ele1 != -1 and ele2 != -1)
					{
						break;
					}
				}

				bool foundNonZero = false;
				int count = 2;
				for (auto i : digits)
				{
					if (i == ele1 and count)
					{
						count--;
					}
					else if ( i == ele2 and count)
					{
						count--;
					}
					else if (i)
					{
						foundNonZero = true;
						break;
					}
				}

				if (foundNonZero)
				{
					bool selected1 = false;
					bool selected2 = false;
					for (int i : digits)
					{
						if (i == ele1 and !selected1)
						{
							selected1 = true;
							continue;
						}
						if (i == ele2 and !selected2)
						{
							selected2 = true;
							continue;
						}
						else
						{
							cout << i;
						}
					}
				}
				else
				{
					cout << 0 << endl;
					return;
				}
			}
		}

	}
	else if (extra == 2)
	{
		if (sz(rem[2]) == 0 and countOf1 < 2)
		{
			cout << 0 << endl;
			return;
		}
		else
		{
			if (sz(rem[2]) >= 1)
			{
				int eleToRmv = *(rem[2].begin());

				bool foundNonZero = false;
				int count = 1;
				for (auto i : digits)
				{
					if (i == eleToRmv and count)
					{
						count--;
					}
					else if (i)
					{
						foundNonZero = true;
						break;
					}
				}
				if (foundNonZero)
				{
					bool selected = false;
					for (int i : digits)
					{
						if (i == eleToRmv and !selected)
						{
							selected = true;
							continue;
						}
						else
						{
							cout << i;
						}
					}
				}
				else
				{
					cout << 0 << endl;
					return;
				}
			}
			else
			{
				int ele1 = -1, ele2 = -1;
				for (auto i = digits.rbegin(); i != digits.rend(); i++)
				{
					int ele  = *i;
					if (ele % 3 == 1 and ele1 == -1)
					{
						ele1 = ele;
					}
					else if (ele % 3 == 1 and ele2 == -1)
					{
						ele2 = ele;
					}
					if (ele1 != -1 and ele2 != -1)
					{
						break;
					}
				}

				debug(ele1, ele2);
				bool foundNonZero = false;
				int count = 2;
				for (auto i : digits)
				{
					if (i == ele1 and count)
					{
						count--;
					}
					else if ( i == ele2 and count)
					{
						count--;
					}
					else if (i)
					{
						foundNonZero = true;
						break;
					}
				}

				if (foundNonZero)
				{
					bool selected1 = false;
					bool selected2 = false;
					for (int i : digits)
					{
						if (i == ele1 and !selected1)
						{
							selected1 = true;
							continue;
						}
						if (i == ele2 and !selected2)
						{
							selected2 = true;
							continue;
						}
						else
						{
							cout << i;
						}
					}
				}
				else
				{
					cout << 0 << endl;
				}

			}
		}
	}

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
	int t = 1; //cin>>t;
	while (t--) solve();
	return 0;
}