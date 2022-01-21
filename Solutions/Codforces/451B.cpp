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

void solve()
{
	int n; cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vi sorted = v;
	sortv(sorted);
	if (sorted == v)
	{
		cout << "yes" << endl;
		cout << 1 << " " << 1 << endl;
		return;
	}

	vi revSorted = v;
	sort(revSorted.rbegin(), revSorted.rend());
	if (v == revSorted)
	{
		cout << "yes" << endl;
		cout << 1 << " " << n << endl;
		return;
	}

	int i = 1;
	int prev = v[0];
	bool segSelected = 0;
	int countOfSegs = 0;
	int l = 0, r = 0;
	while (i < n)
	{
		int cur = v[i];

		if (cur < prev)
		{
			if (!segSelected)
			{
				if (countOfSegs >= 1)
				{
					cout << "no" << endl;
					return;
				}
				countOfSegs++;
				segSelected = 1;
				l = i - 1;
				r = i;
			}
			else
			{
				r = i;
				prev = cur;
			}
			i++;
		}
		else
		{
			prev = cur;
			i++;
			segSelected = 0;
		}
	}

	int idx = 0;
	for (idx = 0; idx < l; idx++)
	{
		if (v[idx] == sorted[idx])
		{
			continue;
		}
		else
		{
			cout << "no" << endl;
			return;
		}
	}

	int curIdx = idx;
	for (int i = r; i >= l; i--)
	{
		if (v[i] == sorted[curIdx++])
		{
			continue;
		}
		else
		{
			cout << "no" << endl;
			return;
		}
	}

	for (int i = r + 1; i < n; i++)
	{
		if (v[i] == sorted[i])
		{
			continue;
		}
		else
		{
			cout << "no" << endl;
			return;
		}
	}

	cout << "yes" << endl;
	cout << l + 1 << " " << r + 1 << endl;

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
