#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define mp make_pair
#define endl '\n'


typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

//const
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};


//useful functions
//#define deb(x) cout<<#x<<": "<<x<<endl;
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define op_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
int gcd(int x, int y) {return y ? gcd(y, x % y) : x;}


void fio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}

const int maxN = 1.5 * 1e7 + 7;
bitset<maxN> primes;
int primeFacCount[maxN];
map<int, int> primeDiv;
map<int, vi> divisors;
void sieve()
{
	primes.set();
	primes[0] = primes[1] = 0;
	for (int i = 2; i < maxN ; i += 2)
	{
		if (i != 2)
			primes[i] = 0;
		divisors[i].pb(2);
	}
	for (int i = 3; i < maxN; i++)
	{
		for (int j = i; j < maxN; j += i)
		{
			if (primes[i])
			{
				if (j != i)
					primes[j] = 0;
				divisors[j].pb(i);
			}
		}
	}
}
//fails for testCase: [4,8,12,24] and so on.
// says delete all
// but we can keep [12,24]
void solve()
{
	sieve();
	int n; cin >> n;
	vi v(n);

	int gcd = 0;
	map<int, int> multiples; // prime and its count
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		vi pf = divisors[v[i]];
		for (int i : pf)
			multiples[i]++;
		gcd = __gcd(gcd, v[i]);
	}

	int ans = 0;
	vi primeFacOfGcd = divisors[gcd];
	for (auto ele : multiples)
	{
		if (!binary_search(primeFacOfGcd.begin(), primeFacOfGcd.end(), ele.ff)) {
			ans = max(ans, ele.ss);;
		}
	}
	if (ans == n or ans == 0) {
		cout << "-1" << endl;
	}
	else {
		cout << n - ans << endl;
	}
}

int32_t main()
{
	fio();
	//setUpLocal();
	return solve(), 0;
}
