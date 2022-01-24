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
#define all(i) i.begin(),i.end()
//---------------------------------------------------------------------------------------------------------//

int gcd(int a, int b) {return (b ? gcd (b, a % b) : a);}

void solve()
{
	int n;
	cin >> n;
	vi v(n), vis(n), ans(n);

	int mx = -1, idx = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		vis[i] = 0;
		if (v[i] > mx)
		{
			mx = v[i];
			idx = i;
		}
	}

	ans[0] = mx;
	vis[idx] = 1;
	int curGcd = mx;

	for (int i = 1; i < n; i++)
	{
		int mxGcd = -1;
		int idx = -1;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				int localGcd = gcd(v[i], curGcd);
				if (localGcd > mxGcd)
				{
					mxGcd = localGcd;
					idx = i;
				}
			}
		}
		ans[i] = v[idx];
		curGcd = mxGcd;
		vis[idx] = 1;
	}

	for (int i : ans)
		cout << i << " ";
	cout << endl;
}

/*
const int maxN = 1e3 + 1;
map<int, vector<pair<int, int>> > primes;

vpi factorize(int n, int k)
{
	int ele = n;
	vpi gcds;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			int count = 0;
			while (n % i == 0)
			{
				n /= i;
				count++;
			}
			primes[i].push_back({ele, count});
			if (k)
			{
				gcds.push_back({i, count});
			}
		}
	}
	if (n != 1)
	{
		primes[n].push_back({ele, 1});
		if (k)
			gcds.push_back({n, 1});
	}
	if (k)
	{
		return gcds;
	}
	else // ignore
	{
		return gcds;
	}
}

void primeFac(int n)
{
	for (int i = 0; i < n; i++)
	{
		factorize(i, 0);
	}
}
void solve()
{
	int n; cin >> n;
	vi v(n);
	ipArr(v, n);

	int mx = *max_element(v.begin(), v.end());
	vpi gcd = factorize(mx, 1);

	map<int, int> marked;
	for (int i : v)
		marked[i] = -1;

	map<int, int> count;
	for (int i : v)
		count[i]++;

	int ans = 0;
	cout << mx << " ";
	ans++;
	marked[mx] = 1;
	count[mx]--;
	while (count[mx] != 0)
	{
		cout << mx << " ";
		ans++;
		count[mx]--;
	}

	for (int i = 1; i < n and ans != n; i++)
	{
		vpi gcds = gcd;

		map<int, int> candidates;
		for (pair<int, int> p : gcds)
		{
			int curPrime = p.ff;
			int curCount = p.ss;
			for (auto i : primes[curPrime])
			{
				int curCand = i.ff;
				int curCandCount = i.ss;
				if (marked[curCand] == 1 or marked[curCand] == 0)
				{
					continue;
				}
				if (candidates[curCand] == 0)
					candidates[curCand] = pow(curPrime, min(curCandCount, curCount));
				else
					candidates[curCand] *= pow(curPrime, min(curCandCount, curCount));
			}
		}
		if (sz(candidates) == 0)
		{
			int mx = -1;
			for (int i : v)
			{
				if (marked[i] == -1)
				{
					if (i > mx)
						mx = i;
				}
			}
			cout << mx << " ";
			ans++;
			marked[mx] = 1;
			count[mx]--;
			while (count[mx] > 0)
			{
				cout << mx << " ";
				ans++;
				count[mx]--;
			}
			gcd = factorize(mx, 1);
			continue;

		}
		int mx = -1;
		int nxtCand;
		for (auto i : candidates)
		{
			if (i.ss > mx)
			{
				mx = i.ss;//gcd
				nxtCand = i.ff;
			}
		}
		cout << nxtCand << " ";
		ans++;
		count[nxtCand]--;
		while (count[nxtCand] != 0)
		{
			cout << nxtCand << " ";
			ans++;
			count[nxtCand]--;
		}
		gcd = factorize(mx, 1);
		marked[nxtCand] = 1;

	}
	cout << endl;
}
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
	//primeFac(maxN);
	while (t--) solve();
	return 0;
}
