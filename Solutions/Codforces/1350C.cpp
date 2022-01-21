#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include <bits/headerfile.hpp>
#else
#define dbg (...)
#endif

//---------------------------------------------------------------------------------------------------------//


#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb push_back
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

// #ifndef ONLINE_JUDGE
// #define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) {
// 	cerr << (*it) << " = " << a << endl;
// 	err(++it, args...);
// }
// #else
// #define debug(...) 1
// #define cerr if(0) cerr
// #endif

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


const int maxN = 2 * 1e5 + 7;

vector<pi> factors[maxN];//<number, vector<pf, power> >

void sieve()
{
	for (int i = 2; i < maxN; i++)
	{
		if (factors[i].empty())
		{
			for (int j = i; j < maxN; j += i)
			{
				int ele = j;
				if (ele % i == 0)
				{
					int power = 0;
					while (ele % i == 0)
					{
						ele /= i;
						power++;
					}
					factors[j].pb({i, power});
				}
			}
		}
	}
}

int binPow(int a, int b)
{
	int res = 1;

	while (b)
	{
		if (b % 2 == 0)
			a *= a, b /= 2;
		else
			res *= a, b--;
	}

	return res;
}

void solve()
{
	int n;
	cin >> n;
	int a[n];
	ipArr(a, n);

	sieve();
	map<int, vi> powers; //<2,<1,3,3,4> 5<1,1,1> 3<1>

	for (int i : a)
	{
		vpi primeWithPower = factors[i];
		for (auto i : primeWithPower)
		{
			powers[i.ff].pb(i.ss);
		}
		//debug(i);
		//debug(primeWithPower);

	}

	int ans = 1;
	for (auto i : powers)
	{

		int count = sz(i.ss);

		// atleast 2 numbers doesnt have a prime, their LCM will not have that prime. hence not present in overall GCD
		if (count <= n - 2)
		{
			continue;
		}
		vi pows = i.ss;
		sortv(pows);

		if (count == n)
		{
			dbg(i.ff, pows[1]); // works in local without semicolon. wont work in oj.be very careful.
			ans *= (binPow(i.ff, pows[1]));
		}
		if (count == n - 1)
		{
			dbg(i.ff, pows[0]);
			ans *= (binPow(i.ff, pows[0]));
		}
	}

	cout << ans << endl;

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
