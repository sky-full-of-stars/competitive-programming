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
	int t;
	cin >> t;

	vector<pair<int, pair<int, int>>> sums;
	for (int i = 0; i < t; i++)
	{
		int n; cin >> n;
		vi v(n);
		int sum = 0;
		for (int pos = 0; pos < n; pos++)
		{
			cin >> v[pos];
			sum +=  v[pos];
		}
		for (int pos = 0; pos < n; pos++)
		{
			sums.push_back({sum - v[pos], {i + 1, pos + 1}});
		}
	}
	sort(all(sums));

	//dbg(sums);

	for (int i = 0; i < sz(sums) - 1; i++)
	{
		if (sums[i].ff == sums[i + 1].ff)
		{
			if (sums[i].ss.ff != sums[i + 1].ss.ff)
			{
				cout << "YES" << endl;
				cout << sums[i].ss.ff << " " << sums[i].ss.ss << endl;
				cout << sums[i + 1].ss.ff << " " << sums[i + 1].ss.ss << endl;
				return;
			}
		}
	}

	cout << "NO" << endl;
	/*
	int t;
	cin >> t;

	vector<vector<int>> v;
	unordered_map<int, int> sumMap;
	unordered_map<int, map<int, int>> eleMap;
	for (int cnt = 0; cnt < t; cnt++)
	{
		int n; cin >> n;
		int sum = 0;
		vi internalV(n);
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> internalV[i];
			sum += internalV[i];
			mp[internalV[i]] = i + 1;
		}
		eleMap[cnt] = mp;
		sortv(internalV);
		sumMap[cnt] = sum;
		v.pb(internalV);
	}

	int n = sz(v);
	for (int i = 0; i < n; i++)
	{
		vi thisV = v[i];
		int thisSum = sumMap[i];
		for (int pos = 0; pos < sz(thisV); pos++)
		{
			int ele = thisV[pos];
			int sumToSearch = thisSum - ele;
			//debug(thisSum, sumToSearch);
			for (int j = i + 1; j < n; j++)
			{
				vi thatV = v[j];
				int thatSum = sumMap[j];
				if (sumToSearch >= thatSum)
				{
					continue;
				}
				else
				{
					int eleToRemoveInThatV = thatSum - sumToSearch;
					//debug(eleToRemoveInThatV);
					if (binary_search(all(thatV), eleToRemoveInThatV))
					{
						cout << "YES" << endl;
						//debug(ele, eleToRemoveInThatV);
						cout << i + 1 << " " << eleMap[i][ele] << endl;
						cout << j + 1 << " " << eleMap[j][eleToRemoveInThatV] << endl;
						return;
					}

				}
			}
		}
	}

	cout << "NO" << endl;
	*/
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